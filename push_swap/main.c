/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:05:32 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/26 15:05:34 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stack *stacks)
{
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}

void	error_handler(t_stack *stacks)
{
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc == 1)
		exit(1);
	stacks = create_stacks(argc - 1, argv);
	sort_stack(stacks, 0);
	return (0);
}
