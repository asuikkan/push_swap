/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:02:57 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/20 14:03:04 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stacks)
{
	if (stacks->top_b < 0)
		return ;
	stacks->top_a++;
	stacks->a[stacks->top_a] = stacks->b[stacks->top_b];
	stacks->top_b--;
}

void	push_b(t_stack *stacks)
{
	if (stacks->top_a < 0)
		return ;
	stacks->top_b++;
	stacks->a[stacks->top_b] = stacks->b[stacks->top_a];
	stacks->top_a--;
}

void	push_a_and_b(t_stack *stacks)
{
	push_a(stacks);
	push_b(stacks);
}
