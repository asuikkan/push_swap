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

static void	check_rotate_b(t_stack *stacks)
{
	if (stacks->size_b > 1 && stacks->b[stacks->size_b - 1] < stacks->b[0])
		rotate_a_and_b(stacks);
	else
		rotate_a(stacks);
}

static void	check_swap_b(t_stack *stacks)
{

	if (stacks->size_b > 1 && stacks->b[stacks->size_b - 1] < stacks->b[stacks->size_b - 2])
		swap_a_and_b(stacks);
	else
		swap_a(stacks);
}

static void	check_rev_b(t_stack *stacks)
{

	if (stacks->size_b > 1 && stacks->b[0] > stacks->b[stacks->size_b - 1])
		reverse_a_and_b(stacks);
	else
		reverse_a(stacks);
}

static void	reset(t_stack *stacks)
{
	int	high;
	int	high_index;
	int	i;

	high = stacks->a[stacks->size_a - 1];
	high_index = stacks->size_a - 1;
	i = stacks->size_a;
	while (--i >= 0)
	{
		if (stacks->a[i] > high)
		{
			high = stacks->a[i];
			high_index = i;
		}
	}
	if (high_index > stacks->size_a / 2)
	{
		while (high_index++ < stacks->size_a)
			rotate_a(stacks);
	}
	else
	{
		while (high_index-- > 0)
			reverse_a(stacks);
	}
}

static void	merge(t_stack *stacks)
{
	while (stacks->size_b > 0)
	{
		if (stacks->a[stacks->size_a - 1] < stacks->b[stacks->size_b - 1])
			rotate_a(stacks);
		else
		{
			push_a(stacks);
			reset(stacks);
		}
	}
}

static void	sort_small(t_stack *stacks)
{
	if (stacks->size_a == 2 && stacks->a[0] < stacks->a[1])
		check_rev_b(stacks);
	else if (stacks->size_a == 3)
	{
		if (stacks->a[0] < stacks->a[2] && stacks->a[0] < stacks->a[1])
		{
			if (stacks->a[1] < stacks->a[2])
				check_swap_b(stacks);
			check_rev_b(stacks);
		}
		else if (stacks->a[0] < stacks->a[2] && stacks->a[0] > stacks->a[1])
			check_rotate_b(stacks);
		else if (stacks->a[0] > stacks->a[2] && stacks->a[1] < stacks->a[2])
			check_swap_b(stacks);
		else if (stacks->a[0] > stacks->a[2] && stacks->a[1] > stacks->a[0])
		{
			check_swap_b(stacks);
			check_rotate_b(stacks);
		}
	}
}

static int	is_sorted(t_stack *stacks)
{
	int	i;
	int	errors;

	errors = 0;
	i = stacks->size_a;
	while (--i > 0)
	{
		if (stacks->a[i] > stacks->a[i - 1])
			return (0);
	}
	merge(stacks);
	return (1);
}

static void	sort_a(t_stack *stacks)
{
	int	min;
	int	min_i;
	int	i;

	i = stacks->size_a - 1;
	min = stacks->a[i];
	while (--i >= 0)
	{
		if (stacks->a[i] < min)
		{
			min = stacks->a[i];
			min_i = i;
		}
	}
	if (min_i >= stacks->size_a / 2)
	{
		while (++min_i < stacks->size_a)
			rotate_a(stacks);
		push_b(stacks);
	}
	else
	{
		while (--min_i >= -1)
			reverse_a(stacks);
		push_b(stacks);
	}
}

static void	rotater(t_stack *stacks, int i)
{
	int	value;

	value = stacks->a[i];
	while (++i < stacks->size_a)
	{
		if (stacks->size_b > 1 && stacks->b[stacks->size_b - 1] > value)
			rotate_a_and_b(stacks);
		else
			rotate_a(stacks);
	}
}

static void	reverser(t_stack *stacks, int i)
{
	int	value;

	value = stacks->a[i];
	while (--i > -2)
	{
		if (stacks->size_b > 1 && stacks->b[stacks->size_b - 1] > value)
			rotate_b(stacks);
		reverse_a(stacks);
	}
}

static void	pusher(t_stack *stacks, int pivot)
{
	int	top;
	int	bottom;

	top = stacks->size_a;
	bottom = -1;
	while (--top > ++bottom)
	{
		if (stacks->a[top] < pivot)
		{
			rotater(stacks, top);
			push_b(stacks);
		}
		else if (stacks->a[bottom] < pivot)
		{
			reverser(stacks, bottom);
			push_b(stacks);
		}
	}
}

void	sort_stack(t_stack *stacks, int *sorted, int split)
{
	int	split_count;
	int	pivot_point;

	pivot_point = 0;
	if (is_sorted(stacks))
		return ;
	if (stacks->size_a < 4)
		sort_small(stacks);
	else
	{
		split_count = 1;
		pivot_point = stacks->size_a - split * split_count;
		while (pivot_point > 0)
		{
			pusher(stacks, sorted[pivot_point]);
			split_count++;
			pivot_point = stacks->size_a - split * split_count;
		}
		sort_a(stacks);
	}
	sort_stack(stacks, sorted, split);
}
