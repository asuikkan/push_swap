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

static void	error_handler(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	validate_arg(char *arg)
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
			error_handler();
		value = value * 10 + (arg[i++] - '0');
		if ((value == LIMIT && sign == 1) || value > LIMIT)
			error_handler();
	}
	value *= sign;
	return (value);
}

void	create_stacks(int count, char **argv)
{
	t_stack	*stacks;
	int		i;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	if (stacks == NULL)
		exit(1);
	stacks->a = ft_memalloc(count);
	stacks->b = ft_memalloc(count);
	if (stacks->a == NULL || stacks->b == NULL)
		exit(1);
	stacks->count_a = count;
	stacks->count_b = 0;
	i = 1;
	while (--count >= 0)
	{
		stacks->a[count] = validate_arg(argv[i++]);
		ft_printf("stack_a[%d] = %d\n", count, stacks->a[count]);
	}
}
