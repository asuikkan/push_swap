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

void	sort_stack(t_stack *stacks)
{
	int	i;
	int	bottom;

	i = stacks->size_a;
	bottom = 0;
	while (--i > 0)
	{
		if (stacks->a[i] > stacks->a[i - 1])
		{
			if (i - bottom > stacks->size_a / 2)
			{
				while (i > 0 && stacks->a[i] > stacks->a[i - 1])
				{
					write(1, "ra\n", 3);
					i--;
				}
			}
		}
	}
}
