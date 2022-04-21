/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:01:13 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/15 16:01:15 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_instr *cmds)
{
	t_instr	*temp;

	while (cmds)
	{
		temp = cmds->next;
		free(cmds);
		cmds = temp;
	}
}

void	error_handler(t_stack *stacks, t_instr *cmds)
{
	if (cmds)
		free_list(cmds);
	if (stacks)
	{
		if (stacks->a)
			free(stacks->a);
		if (stacks->b)
			free(stacks->b);
		free(stacks);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	t_instr	*cmds;

	if (argc == 1)
		exit(1);
	stacks = create_stacks(argc - 1, argv);
	cmds = read_input(stacks);
	execute_cmds(stacks, cmds);
	return (0);
}
