/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:43:29 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/21 16:43:32 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmds(t_stack *stacks, t_instr *cmds)
{
	int	check;
	int	i;
	int	j;

	while (cmds)
	{
		cmds->func(stacks);
		j = stacks->top_a + 1;
		while (--j >= 0)
			ft_printf("stack_a[%d] = %d\n", j, stacks->a[j]);
		ft_printf("\n");
		cmds = cmds->next;
	}
	check = 1;
	i = stacks->top_a;
	while (i > 0)
	{
		if (stacks->a[i] > stacks->a[i - 1])
		{
			check = 0;
			break ;
		}
		i--;
	}
	if (check == 0 || stacks->top_b >= 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
