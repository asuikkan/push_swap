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
	int		*sorted;
	int		high_limit;

	if (argc == 1)
		exit(1);
	if (argc == 3 && argv[1][0] == '-')
		stacks = options(argv);
	else
		stacks = create_stacks(argc - 1, argv);
	sorted = sort_array(stacks);
	high_limit = divide_array(stacks, sorted);
	sort_stack(stacks, high_limit, sorted[0]);
	free(sorted);
	free_stacks(stacks);
	return (0);
}
