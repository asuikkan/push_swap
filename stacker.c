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
	stacks->top_a = count - 1;
	stacks->top_b = -1;
	return (stacks);
}

static void	check_duplicates(t_stack *stacks, int count)
{
	int	i;

	i = stacks->top_a;
	while (--i > count)
	{
		if (stacks->a[count] == stacks->a[i])
			error_handler(stacks);
	}
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

t_stack	*create_stacks(int count, char **argv)
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
		check_duplicates(stacks, count);
	}
	return (stacks);
}
