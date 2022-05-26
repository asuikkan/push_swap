/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:43:29 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/21 16:43:32 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_operation(void (*func)(t_stack *))
{
	ft_printf("OPERATION: ");
	if (func == &swap_a)
		ft_printf("sa");
	else if (func == &swap_b)
		ft_printf("sb");
	else if (func == &swap_a_and_b)
		ft_printf("ss");
	else if (func == &push_a)
		ft_printf("pa");
	else if (func == &push_b)
		ft_printf("pb");
	else if (func == &rotate_a)
		ft_printf("ra");
	else if (func == &rotate_b)
		ft_printf("rb");
	else if (func == &rotate_a_and_b)
		ft_printf("rr");
	else if (func == &reverse_a)
		ft_printf("rra");
	else if (func == &reverse_b)
		ft_printf("rrb");
	else if (func == &reverse_a_and_b)
		ft_printf("rrr");
}

static void	print_stacks(t_stack *stacks, void (*func)(t_stack *))
{
	int			high;
	static int	count;

	print_operation(func);
	ft_printf(" | count: %d", ++count);
	if (stacks->size_a > stacks->size_b)
		high = stacks->size_a - 1;
	else
		high = stacks->size_b - 1;
	ft_printf("\n\n");
	while (high >= 0)
	{
		if (stacks->size_a - 1 < high)
			ft_printf("%11c", ' ');
		else
			ft_printf("%11d", stacks->a[high]);
		ft_printf("\t");
		if (stacks->size_b - 1 < high)
			ft_printf("%11c\n", ' ');
		else
			ft_printf("%11d\n", stacks->b[high]);
		high--;
	}
	ft_printf("-----------\t-----------\n  STACK A\t  STACK B\n\n", ' ');
}

void	execute_cmds(t_stack *stacks, t_instr *cmds, int print_flag)
{
	int	check;
	int	i;

	while (cmds)
	{
		cmds->func(stacks);
		if (print_flag)
			print_stacks(stacks, cmds->func);
		cmds = cmds->next;
	}
	check = 1;
	i = stacks->size_a - 1;
	while (i > 0)
	{
		if (stacks->a[i] > stacks->a[i - 1])
		{
			check = 0;
			break ;
		}
		i--;
	}
	if (check == 0 || stacks->size_b > 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
