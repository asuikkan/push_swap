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
	write(2, "Error\n", 6);
	exit(1);
}

static t_stack	*options(char **argv)
{
	int		i;
	t_stack	*stacks;

	i = 1;
	while (argv[1][i])
	{
		if (argv[1][i] == 'r')
			stacks = read_file(argv[2]);
		i++;
	}
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	t_instr	*cmds;

	if (argc == 1)
		exit(1);
	if (argc == 3 && argv[1][0] == '-')
		stacks = options(argv);
	else
		stacks = create_stacks(argc - 1, argv);
	cmds = read_input(stacks);
	execute_cmds(stacks, cmds);
	free_stacks(stacks);
	free_list(cmds);
	return (0);
}
