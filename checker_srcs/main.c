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

#include "checker.h"

static void	free_stacks(t_stack *stacks)
{
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}

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
		free_stacks(stacks);
	(void) stacks;
	(void) cmds;
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int			print_flag;
	int			start;
	t_stack		*stacks;
	t_instr		*cmds;

	if (argc == 1)
		exit(1);
	start = 1;
	print_flag = 0;
	if ((argv[1][0] == '-' && argv[1][1] == 'r') && !argv[1][2])
	{
		print_flag = 1;
		start++;
	}
	stacks = create_stacks(argc - start, argv, start);
	cmds = read_input(stacks);
	execute_cmds(stacks, cmds, print_flag);
	free_stacks(stacks);
	free_list(cmds);
	return (0);
}
