/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:34:42 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/15 16:34:43 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_handler(t_stack *stacks)
{
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

static t_stack	*initialize(int count)
{
	t_stack	*stacks;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	if (stacks == NULL)
		error_handler(stacks);
	stacks->a = ft_memalloc(count);
	stacks->b = ft_memalloc(count);
	if (stacks->a == NULL || stacks->b == NULL)
		error_handler(stacks);
	stacks->count_a = count;
	stacks->count_b = 0;
	return (stacks);
}

static int	validate_arg(int *integer, char *arg)
{
	long	value;
	int		sign;
	int		i;

	sign = 1;
	value = 0;
	i = 0;
	if (arg[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		value = value * 10 + (arg[i++] - '0');
		if ((value == LIMIT && sign == 1) || value > LIMIT)
			return (0);
	}
	value *= sign;
	*integer = value;
	return (1);
}

void	create_stacks(int count, char **argv)
{
	t_stack	*stacks;
	int		i;

	stacks = initialize(count);
	i = 1;
	while (--count >= 0)
	{
		if (!validate_arg(&stacks->a[count], argv[i++]))
			error_handler(stacks);
		ft_printf("stack_a[%d] = %d\n", count, stacks->a[count]);
	}
}
