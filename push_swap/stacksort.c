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
		{
			if (errors)
				return (0);
			errors++;
		}
	}
	if (errors)
	{
		if (stacks->size_a < 4)
			sort_small(stacks);
		else
			reset(stacks);
	}
	merge(stacks);
	return (1);
}

static void	push_lows(t_stack *stacks, int high_limit)
{
	int	top;
	int	bottom;

	top = stacks->size_a;
	bottom = -1;
	while (--top > ++bottom)
	{
		if (stacks->a[top] < high_limit)
		{
			while (++top < stacks->size_a)
				check_rotate_b(stacks);
			push_b(stacks);
			break ;
		}
		if (stacks->a[bottom] < high_limit)
		{
			while (--bottom >= -1)
				check_rev_b(stacks);
			push_b(stacks);
			break ;
		}
	}
}

void	sort_stack(t_stack *stacks, int high_limit)
{
	if (is_sorted(stacks))
		return ;
	if (stacks->size_a < 4)
		sort_small(stacks);
	else
		push_lows(stacks, high_limit);
	sort_stack(stacks, high_limit);
}
