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

static int	count_moves(t_stack *stacks, int *target[4])
{
	int	temp[3];
	int	i;
	int	j;
	int	pos;
	int	target_i;
	int	lowest;

	i = stacks->size_a;
	while (--i >= 0)
	{
		pos = find_position(stacks->b, stacks->size_b, stacks->a[i]);
		if (stacks->size_a - 1 - i >= stacks->size_b - 1 - pos)
		{
			temp[0] = stacks->size_a - 1 - i;
			temp[1] = pos + 1;
			temp[2] = i + 1 + stacks->size_b - 1 - pos;
		}
		else
		{
			temp[0] = stacks->size_b - 1 - i;
			temp[1] = i + 1;
			temp[2] = pos + 1 + stacks->size_a - 1 - i;
		}
		lowest = -1;
		j = -1;
		while (++j < 4)
		{
			if (lowest == -1 || temp[j] < lowest)
				lowest = temp[j];
		}
		j = -1;
		while (++j < 4)
		{
			if (*target[j] == -1 || lowest < *target[j])
			{
				*target = temp;
				target_i = i;
				break ;
			}
		}
	}
	return (target_i);
}

static void	rotater(t_stack *stacks, int target_i)
{
	int	pos;
	int	val_b;
	int	val_a;

	val_a = stacks->a[target_i];
	pos = find_position(stacks->b, stacks->size_b, val_a);
	val_b = stacks->b[pos];
	if (stacks->size_a - 1 - target_i >= stacks->size_b - 1 - pos)
	{
		while (stacks->b[stacks->size_b - 1] != val_b)
			rotate_a_and_b(stacks);
		while (stacks->a[stacks->size_a - 1] != val_a)
			rotate_a(stacks);
	}
	else
	{
		while (stacks->a[stacks->size_a - 1] != val_a)
			rotate_a_and_b(stacks);
		while (stacks->b[stacks->size_b - 1] != val_b)
			rotate_b(stacks);
	}
}

static void	reverser(t_stack *stacks, int target_i)   //continue from here!
{
	int	pos;

	pos = find_position(stacks->b, stacks->size_b, stacks->a[target_i]);
}

static void	rot_rev(t_stack *stacks, int target_i)
{
	int	pos;

	pos = find_position(stacks->b, stacks->size_b, stacks->a[target_i]);
}

static void	rotate_to_pos(t_stack *stacks, int target[4], int target_i)
{
	if (target[0] <= target[1] && target[0] <= target[2])
		rotater(stacks, target_i);
	else if (target[1] <= target[0] && target[1] <= target[2])
		reverser(stacks, target_i);
	else
		rot_rev(stacks, target_i);
}

static void	pusher(t_stack *stacks)
{
	int	target[4];
	int	i;
	int	target_i;

	while (stacks->size_b < 2)
		push_b(stacks);
	while (stacks->size_a > 1)
	{
		i = 0;
		while (i < 4)
			target[i++] = -1;
		target_i = count_moves(stacks, &target);
		rotate_to_pos(stacks, target, target_i);
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
