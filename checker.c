/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:46:28 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/22 11:46:35 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*check_reverse(char *line))(t_stack *stacks)
{
	if (*line++ == 'r')
	{
		if (*line == 'a')
			return (&reverse_a);
		if (*line == 'b')
			return (&reverse_b);
		if (*line == 'r')
			return (&reverse_a_and_b);
	}
	return (NULL);
}

void	(*check_rotate(char *line))(t_stack *stacks)
{
	if (ft_strlen(line) > 2)
		return (NULL);
	if (ft_strlen(line) == 2)
		return (check_reverse(line));
	if (*line == 'a')
		return (&rotate_a);
	if (*line == 'b')
		return (&rotate_b);
	if (*line == 'r')
		return (&rotate_a_and_b);
	return (NULL);
}

void	(*check_push(char *line))(t_stack *stacks)
{
	if (ft_strlen(line) != 1)
		return (NULL);
	if (*line == 'a')
		return (&push_a);
	if (*line == 'b')
		return (&push_b);
	return (NULL);
}

void	(*check_swap(char *line))(t_stack *stacks)
{
	if (ft_strlen(line) != 1)
		return (NULL);
	if (*line == 'a')
		return (&swap_a);
	if (*line == 'b')
		return (&swap_b);
	if (*line == 's')
		return (&swap_a_and_b);
	return (NULL);
}
