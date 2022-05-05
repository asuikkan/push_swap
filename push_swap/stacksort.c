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

static int	check_b(t_stack *stacks)
{
	if (stacks->size_b > 1)
	{
		if (stacks->b[stacks->size_b - 1] < stacks->b[0])
		{
			reverse_a_and_b(stacks);
			return (1);
		}
		if (stacks->b[stacks->size_b - 1] > stacks->b[stacks->size_b - 2])
		{
			swap_a_and_b(stacks);
			return (1);
		}
	}
	return (0);
}

static void	sort_small(t_stack *stacks)
{
	int	pivot;

	pivot = stacks->a[0];
	if (stacks->a[2] > pivot)
	{
		if (stacks->a[1] > stacks->a[2])
		{
			if (!check_rev_b(stacks))
		}
		else
		{
			if (!check_b(stacks))
				swap_a(stacks);
		}
		reverse_a(stacks);
	}
}

void	sort_stack(t_stack *stacks, int *sorted)
{
	sorted = NULL;
	if (stacks->size_a == 3)
		sort_small(stacks);
}
