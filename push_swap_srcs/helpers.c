/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:28:16 by asuikkan          #+#    #+#             */
/*   Updated: 2022/05/26 15:28:18 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_b(t_stack *stacks)
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

int	is_sorted(int *stack, int size)
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

void	sort_small(t_stack *stacks)
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
