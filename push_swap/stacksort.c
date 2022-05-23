/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:24:30 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/28 14:24:31 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest(int *stack, int size)
{
	int	i;
	int	max;
	int	max_i;

	i = size - 1;
	max_i = i;
	max = stack[max_i];
	while (--i >= 0)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			max_i = i;
		}
	}
	return (max_i);
}

static void	reset_b(t_stack *stacks)
{
	int	max_i;

	max_i = find_highest(stacks->b, stacks->size_b);
	if (max_i > (stacks->size_b - 1) / 2)
	{
		while (max_i++ < stacks->size_b - 1)
			rotate_b(stacks);
	}
	else
	{
		while (max_i-- > -1)
			reverse_b(stacks);
	}
}

static int	find_position(int *stack, int size, int value)
{
	int	start;
	int	i;

	start = find_highest(stack, size);
	if (value > stack[start])
		return (start);
	i = start;
	while (--i != start)
	{
		if (i == -1)
			i = size;
		else if (i == size - 1)
		{
			if (stack[i] < value && stack[0] > value)
				return (i);
		}
		else
		{
			if (stack[i] < value && stack[i + 1] > value)
				return (i);
		}
	}
	return (start);
}

static int	is_sorted(int *stack, int size)
{
	int	i;

	i = size;
	while (--i > 0)
	{
		if (stack[i] > stack[i - 1])
			return (0);
	}
	return (1);
}

static void	merge(t_stack *stacks)
{
	while (stacks->size_b > 0)
	{
		push_a(stacks);
	}
}

static void	sort_small(t_stack *stacks)
{
	if (stacks->size_a == 2 && stacks->a[0] < stacks->a[1])
		reverse_a(stacks);
	else if (stacks->size_a == 3)
	{
		if (stacks->a[0] < stacks->a[2] && stacks->a[0] < stacks->a[1])
		{
			if (stacks->a[1] < stacks->a[2])
				swap_a(stacks);
			reverse_a(stacks);
		}
		else if (stacks->a[0] < stacks->a[2] && stacks->a[0] > stacks->a[1])
			rotate_a(stacks);
		else if (stacks->a[0] > stacks->a[2] && stacks->a[1] < stacks->a[2])
			swap_a(stacks);
		else if (stacks->a[0] > stacks->a[2] && stacks->a[1] > stacks->a[0])
		{
			swap_a(stacks);
			rotate_a(stacks);
		}
	}
}

static int	count_moves(t_stack *stacks)
{
	int	i;
	int	pos;
	int	moves;
	int	fewest;
	int	target_i;

	fewest = -1;
	i = stacks->size_a;
	while (--i >= 0)
	{
		pos = find_position(stacks->b, stacks->size_b, stacks->a[i]);
		if (stacks->size_a - 1 - i <= stacks->size_b - 1 - pos)
		{
			moves = stacks->size_b - 1 - pos;
			if (moves > i + 1)
				moves = i + 1;
			if (moves > (stacks->size_b - 1 - pos) + (i + 1))
				moves = (stacks->size_b - 1 - pos) + (i + 1);
		}
		else
		{
			moves = stacks->size_a - 1 - i;
			if (moves > pos + 1)
				moves = pos + 1;
			if (moves > (stacks->size_a - 1 - i) + (pos + 1))
				moves = (stacks->size_a - 1 - i) + (pos + 1);
		}
		if (fewest == -1 || moves < fewest)
		{
			fewest = moves;
			target_i = i;
		}
	}
	//ft_printf("moves = %d\n", moves);
	//ft_printf("target_i = %d\n", target_i);
	return (target_i);
}

static void	rotate_to_pos(t_stack *stacks, int target_i)
{
	int	value;
	int	target;
	int	pos;

	value = stacks->a[target_i];
	pos = find_position(stacks->b, stacks->size_b, value);
	target = stacks->b[pos];
	//ft_printf("target = %d\n", target);
	//ft_printf("value = %d\n", value);
	if (stacks->size_a - 1 - target_i <= stacks->size_b - 1 - pos)
	{
		if (stacks->size_b - 1 - pos <= target_i + 1)
		{
			while (value != stacks->a[stacks->size_a - 1])
				rotate_a_and_b(stacks);
			while (target != stacks->b[stacks->size_b - 1])
				rotate_b(stacks);
		}
		else
		{
			while (target != stacks->b[stacks->size_b - 1])
				reverse_a_and_b(stacks);
			while (value != stacks->a[stacks->size_a - 1])
				reverse_a(stacks);
		}
	}
	else
	{
		if (stacks->size_a - 1 - target_i <= pos + 1)
		{
			while (target != stacks->b[stacks->size_b - 1])
				rotate_a_and_b(stacks);
			while (value != stacks->a[stacks->size_a - 1])
				rotate_a(stacks);
		}
		else
		{
			while (value != stacks->a[stacks->size_a - 1])
				reverse_a_and_b(stacks);
			while (target != stacks->b[stacks->size_b - 1])
				reverse_b(stacks);
		}
	}
}

static void	pusher(t_stack *stacks)
{
	int	target_i;

	while (stacks->size_b < 2)
		push_b(stacks);
	while (stacks->size_a > 1)
	{
		target_i = count_moves(stacks);
		rotate_to_pos(stacks, target_i);
		push_b(stacks);
	}
	reset_b(stacks);
}

void	sort_stack(t_stack *stacks)
{
	if (is_sorted(stacks->a, stacks->size_a))
		return ;
	if (stacks->size_a < 4)
		sort_small(stacks);
	else
	{
		pusher(stacks);
		merge(stacks);
	}
}
