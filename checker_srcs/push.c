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

#include "checker.h"

void	push_a(t_stack *stacks)
{
	if (stacks->size_b == 0)
		return ;
	stacks->size_b--;
	stacks->a[stacks->size_a] = stacks->b[stacks->size_b];
	stacks->size_a++;
}

void	push_b(t_stack *stacks)
{
	if (stacks->size_a == 0)
		return ;
	stacks->size_a--;
	stacks->b[stacks->size_b] = stacks->a[stacks->size_a];
	stacks->size_b++;
}
