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
	int	i;

	if (stacks->size_a < 2)
		return ;
	i = stacks->size_a - 1;
	temp = stacks->a[i - 1];
	stacks->a[i - 1] = stacks->a[i];
	stacks->a[i] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b < 2)
		return ;
	i = stacks->size_b - 1;
	temp = stacks->b[i - 1];
	stacks->b[i - 1] = stacks->b[i];
	stacks->b[i] = temp;
	write(1, "sb\n", 3);
}

void	swap_a_and_b(t_stack *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
	write(1, "ss\n", 3);
}
