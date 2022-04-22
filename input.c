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

static void	add_node(t_instr *head, t_instr *new)
{
	t_instr	*temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

static void	(*check_instruction(char *line))(t_stack *stacks)
{
	char	*temp;

	temp = line;
	if (*temp == 's')
		return (check_swap(++temp));
	if (*temp == 'p')
		return (check_push(++temp));
	if (*temp == 'r')
		return (check_rotate(++temp));
	return (NULL);
}

t_instr	*read_input(t_stack *stacks)
{
	t_instr	*head;
	t_instr	*instr;
	void	(*func)(t_stack *);
	char	*line;
	int		ret;

	head = NULL;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			error_handler(stacks, head);
		if (ret == 0)
			break ;
		func = check_instruction(line);
		instr = new_instr(func);
		if (!instr)
			error_handler(stacks, head);
		if (!head)
			head = instr;
		else
			add_node(head, instr);
		ft_strdel(&line);
	}
	return (head);
}
