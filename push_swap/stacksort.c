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

static void	reset_b(t_stack *stacks)
{
	int	max;
	int	max_i;
	int	i;

	i = stacks->size_b - 1;
	max = stacks->b[i];
	while (--i >= 0)
	{
		if (stacks->b[i] > max)
		{
			max = stacks->b[i];
			max_i = i;
		}
	}
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
	int	i;
	int	pos;

	i = size;
	pos = size;
	while (--i > 0)
	{
		if (stack[i] > value && stack[i - 1] < value)
			return (i - 1);
	}
	return (pos);
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
		//if (target_i == i)
		//	ft_printf("pos = %d\n", pos);
	}
	//ft_printf("moves = %d\n", moves);
	//ft_printf("target_i = %d\n", target_i);
	return (target_i);
}

static void	rotater(t_stack *stacks, int i)
{
	int	value;
	int	pos;

	value = stacks->a[i];
	pos = find_position(stacks->b, stacks->size_b, value);
	if (pos == stacks->size_b)
		reset_b(stacks);
	//ft_printf("pos = %d\n", pos);
	if (pos < (stacks->size_b - 1 - pos) - (stacks->size_a - 1 - i))
	{
		while (pos-- > -1)
			reverse_b(stacks);
	}
	else
	{
		while (i < stacks->size_a - 1 && pos < stacks->size_b - 1)
		{
			rotate_a_and_b(stacks);
			i++;
			pos++;
		}
		while (pos++ < stacks->size_b - 1)
			rotate_b(stacks);
	}
	while (++i < stacks->size_a)
		rotate_a(stacks);
}

static void	reverser(t_stack *stacks, int i)
{
	int	value;
	int	pos;

	value = stacks->a[i];
	pos = find_position(stacks->b, stacks->size_b, value);
	if (pos == stacks->size_b)
		reset_b(stacks);
	//ft_printf("pos = %d\n", pos);
	if (stacks->size_b - pos < pos - i)
	{
		while (pos++ < stacks->size_b)
			rotate_b(stacks);
	}
	else
	{
		while (i > -1 && pos > -1)
		{
			reverse_a_and_b(stacks);
			i--;
			pos--;
		}
		while (pos-- > -1)
			reverse_b(stacks);
	}
	while (i-- > -1)
		reverse_a(stacks);
}

static void	pusher(t_stack *stacks)
{
	int	target_i;

	while (stacks->size_b < 2)
		push_b(stacks);
	while (stacks->size_a > 0)
	{
		target_i = count_moves(stacks);
		if (target_i >= (stacks->size_a - 1) / 2)
			rotater(stacks, target_i);
		else
			reverser(stacks, target_i);
		push_b(stacks);
	}
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
