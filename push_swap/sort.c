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

static void	sort_b(t_stack *stacks)
{
	int	i;

	i = stacks->size_b - 1;
}

void	sort_stack(t_stack *stacks, int pivot)
{
	int	i;
	int	j;
	int	pivot_index;

	i = stacks->size_a - 1;
	pivot_index = 0;
	while (i > pivot_index)
	{
		if (stacks->a[i] > pivot)
		{
			if (i - 1 == pivot_index)
				swap_a(stacks);
			else
			{
				j = stacks->size_a - 1;
				while (j-- > i)
				{
					push_b(stacks);
					pivot_index++;
				}
				rotate_a(stacks);
				i = stacks->size_a - 1;
			}
			pivot_index++;
		}
		else
			i--;
	}
	if (pivot_index == stacks->size_a - 1)
		return ;
	sort_b(stacks);
}
