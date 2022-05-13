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

#include "checker.h"

void	rotate_a(t_stack *stacks)
{
	int	i;
	int	temp;

	i = stacks->size_a - 1;
	temp = stacks->a[i];
	while (--i >= 0)
		stacks->a[i + 1] = stacks->a[i];
	stacks->a[0] = temp;
	ft_printf("INSTRUCTION: ra");
}

void	rotate_b(t_stack *stacks)
{
	int	i;
	int	temp;

	i = stacks->size_b - 1;
	temp = stacks->b[i];
	while (--i >= 0)
		stacks->b[i + 1] = stacks->b[i];
	stacks->b[0] = temp;
	ft_printf("INSTRUCTION: rb");
}

void	rotate_a_and_b(t_stack *stacks)
{
	int	i;
	int	temp;

	i = stacks->size_a - 1;
	temp = stacks->a[i];
	while (--i >= 0)
		stacks->a[i + 1] = stacks->a[i];
	stacks->a[0] = temp;
	i = stacks->size_b - 1;
	temp = stacks->b[i];
	while (--i >= 0)
		stacks->b[i + 1] = stacks->b[i];
	stacks->b[0] = temp;
	ft_printf("INSTRUCTION: rr");
}
