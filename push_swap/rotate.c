/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:04:12 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/22 12:04:14 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stacks)
{
	int	i;
	int	temp;

	if (stacks->size_a < 2)
		return ;
	i = stacks->size_a - 1;
	temp = stacks->a[i];
	while (--i >= 0)
		stacks->a[i + 1] = stacks->a[i];
	stacks->a[0] = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stacks)
{
	int	i;
	int	temp;

	if (stacks->size_b < 2)
		return ;
	i = stacks->size_b - 1;
	temp = stacks->b[i];
	while (--i >= 0)
		stacks->b[i + 1] = stacks->b[i];
	stacks->b[0] = temp;
	write(1, "rb\n", 3);
}

void	rotate_a_and_b(t_stack *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
	write(1, "rr\n", 3);
}
