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

static int	divide_array(t_stack *stacks, int *sorted)
{
	int	sub_stack;
	int	denom;

	denom = 4;
	sub_stack = stacks->size_a / denom;
	while (sub_stack > 15)
	{
		denom++;
		sub_stack = stacks->size_a / denom;
	}
	return (sorted[sub_stack]);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		*sorted;
	int		high_limit;

	if (argc == 1)
		exit(1);
	stacks = create_stacks(argc - 1, argv);
	sorted = sort_array(stacks);
	high_limit = divide_array(stacks, sorted);
	sort_stack(stacks, high_limit);
	free(sorted);
	free_stacks(stacks);
	return (0);
}
