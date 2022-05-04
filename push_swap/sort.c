/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:24:30 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/28 14:24:31 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_stack(t_stack *stacks)
{
	int	i;
	int	min;
	int	min_index;

	i = stacks->size_a - 1;
	min = stacks->a[i];
	min_index = stacks->size_a - 1;
	while (i >= 0)
	{
		if (stacks->a[i] < min)
		{
			min = stacks->a[i];
			min_index = i;
		}
		i--;
	}
	if (min_index > (stacks->size_a - 1) / 2)
	{
		while (min_index++ < stacks->size_a - 1)
			rotate_a(stacks);
	}
	else
	{
		while (min_index-- >= -1)
			reverse_a(stacks);
	}
}

static void	merge_stacks(t_stack *stacks)
{
	if (stacks->size_b == 0)
		return ;
	if (stacks->a[stacks->size_a - 1] < stacks->b[stacks->size_b - 1])
		rotate_a(stacks);
	else
		push_a(stacks);
	merge_stacks(stacks);
}

void	sort_stack(t_stack *stacks, int pivot_index)
{
	int	i;
	int	j;

	i = stacks->size_a;
	if (pivot_index >= stacks->size_a - 1)
			return ;
	while (--i > pivot_index)
	{
		if (stacks->a[i] > stacks->a[pivot_index])
		{
			if (pivot_index == stacks->size_a - 2)
				swap_a(stacks);
			else if (pivot_index == 0)
				rotate_a(stacks);
			else
			{
				j = stacks->size_a - 1;
				while (j-- > pivot_index)
					push_b(stacks);
			}
		}
	}
	sort_stack(stacks, pivot_index + 1);
	merge_stacks(stacks);
	reset_stack(stacks);
}
