/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:13:38 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/20 11:13:40 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_swap(char *line)
{

	if (*line == 's')

}

static void	check_instruction(char *line)
{
	t_instr	*instr;
	t_instr	*head;
	char	*temp;
	int		i;

	temp = line;
	i = 0;
	while (*temp)
	{
		if (*temp == 's')
			check_swap(temp++);
	}
}

void	read_input(t_stack *stacks)
{
	char	*line;
	int		ret;

	ret = get_next_line(0, &line);
	while (ret == 1)
	{
		check_instruction(line);
		ft_strdel(&line);
		ret = get_next_line(0, &line);
	}
	if (ret == -1)
	{
		if (line)
			free(line);
		error_handler(stacks);
	}
}
