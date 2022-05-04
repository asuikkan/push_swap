/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:04:20 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/22 12:04:21 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_stack *stacks)
{
	int	i;
	int	temp;

	if (stacks->size_a < 2)
		return ;
	i = 0;
	temp = stacks->a[i];
	while (++i <= stacks->size_a - 1)
		stacks->a[i - 1] = stacks->a[i];
	stacks->a[stacks->size_a - 1] = temp;
	write(1, "rra\n", 4);
}

void	reverse_b(t_stack *stacks)
{
	int	i;
	int	temp;

	if (stacks->size_b < 2)
		return ;
	i = 0;
	temp = stacks->b[i];
	while (++i <= stacks->size_b - 1)
		stacks->b[i - 1] = stacks->b[i];
	stacks->b[stacks->size_b - 1] = temp;
	write(1, "rrb\n", 4);
}

void	reverse_a_and_b(t_stack *stacks)
{
	reverse_a(stacks);
	reverse_b(stacks);
	write(1, "rrr\n", 4);
}
