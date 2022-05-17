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
	int	i;
	int	max_i;
	int	max;

	i = stacks->size_b - 1;
	max_i = i;
	max = stacks->b[i];
	while (--i >= 0)
	{
		if (stacks->b[i] > max)
		{
			max = stacks->b[i];
			max_i = i;
		}
	}
	if (max_i > stacks->size_b / 2)
	{
		while (++max_i < stacks->size_b)
			rotate_b(stacks);
	}
	else
	{
		while (stacks->size_b > 1 && max_i-- > -1)
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

/*static void	reset(t_stack *stacks)
{
	int	min;
	int	min_index;
	int	i;

	min = stacks->a[stacks->size_a - 1];
	min_index = stacks->size_a - 1;
	i = stacks->size_a;
	while (--i >= 0)
	{
		if (stacks->a[i] > min)
		{
			min = stacks->a[i];
			min_index = i;
		}
	}
	if (min_index > stacks->size_a / 2)
	{
		while (min_index++ < stacks->size_a)
			rotate_a(stacks);
	}
	else
	{
		while (min_index-- > -1)
			reverse_a(stacks);
	}
}*/

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

static void	rotater(t_stack *stacks, int i)
{
	int	value;
	int	pos;

	value = stacks->a[i];
	if (stacks->size_b > 1)
	{
		pos = find_position(stacks->b, stacks->size_b, value);
		if (pos == stacks->size_b && stacks->b[0] < value)
			reset_b(stacks);
		if (pos < (stacks->size_b - pos) - (stacks->size_a - i))
		{
			while (pos-- < -1)
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
	}
	while (++i < stacks->size_a)
		rotate_a(stacks);
}

static void	reverser(t_stack *stacks, int i)
{
	int	value;
	int	pos;

	value = stacks->a[i];
	if (stacks->size_b > 1)
	{
		pos = find_position(stacks->b, stacks->size_b, value);
		if (pos == stacks->size_b && stacks->b[0] < value)
			reset_b(stacks);
		if (stacks->size_b - pos < pos - i)
		{
			while (pos++ < stacks->size_b - 1)
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
	}
	while (i-- > -1)
		reverse_a(stacks);
}

static void	pusher(t_stack *stacks, int pivot)
{
	int	top;
	int	bottom;

	top = stacks->size_a;
	bottom = -1;
	while (--top > ++bottom)
	{
		if (stacks->a[top] <= pivot)
		{
			rotater(stacks, top);
			push_b(stacks);
			top = stacks->size_a;
			bottom = -1;
		}
		else if (stacks->a[bottom] <= pivot)
		{
			reverser(stacks, bottom);
			push_b(stacks);
			top = stacks->size_a;
			bottom = -1;
		}
	}
}

static void	sort_a(t_stack *stacks)
{
	int	min;
	int	i;

	while (!is_sorted(stacks->a, stacks->size_a))
	{
		i = stacks->size_a;
		min = stacks->a[stacks->size_a - 1];
		if (stacks->size_a < 4)
			sort_small(stacks);
		else
		{
			while (--i >= 0)
			{
				if (stacks->a[i] < min)
					min = stacks->a[i];
			}
			pusher(stacks, min);
		}
	}
	reset_b(stacks);
	merge(stacks);
}

void	sort_stack(t_stack *stacks, int *sorted, int split, int count)
{
	int	split_count;
	int	pivot_point;

	pivot_point = 0;
	if (is_sorted(stacks->a, stacks->size_a))
		return ;
	if (stacks->size_a < 4)
		sort_small(stacks);
	else
	{
		split_count = 1;
		pivot_point = count - split * split_count;
		while (pivot_point > 0)
		{
			pusher(stacks, sorted[pivot_point]);
			split_count++;
			pivot_point = count - split * split_count;
		}
		sort_a(stacks);
	}
}
