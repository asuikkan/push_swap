/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:54:08 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/20 13:54:10 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stacks)
{
	int	temp;

	if (stacks->top_a < 1)
		return ;
	temp = stacks->a[stacks->top_a - 1];
	stacks->a[stacks->top_a - 1] = stacks->a[stacks->top_a];
	stacks->a[stacks->top_a] = temp;
}

void	swap_b(t_stack *stacks)
{
		int	temp;

	if (stacks->top_b < 1)
		return ;
	temp = stacks->b[stacks->top_b - 1];
	stacks->b[stacks->top_b - 1] = stacks->b[stacks->top_b];
	stacks->b[stacks->top_b] = temp;
}

void	swap_a_and_b(t_stack *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
