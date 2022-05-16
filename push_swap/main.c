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

static int	divide_array(t_stack *stacks)
{
	int	split;
	int	denom;

	denom = 4;
	split = (stacks->size_a - 1) / denom;
	while (split > 15)
	{
		denom++;
		split = (stacks->size_a - 1) / denom;
	}
	return (split);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		*sorted;
	int		split;

	if (argc == 1)
		exit(1);
	stacks = create_stacks(argc - 1, argv);
	sorted = sort_array(stacks);
	split = divide_array(stacks);
	sort_stack(stacks, sorted, split, stacks->size_a);
	free(sorted);
	free_stacks(stacks);
	return (0);
}
