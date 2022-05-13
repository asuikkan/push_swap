/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:13:38 by asuikkan          #+#    #+#             */
/*   Updated: 2022/05/13 12:03:15 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	(*check_buffer(char *buf))(t_stack *stacks)
{
	int		i;
	char	line[4];

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			line[i] = '\0';
			return (check_instruction(line));
		}
		line[i] = buf[i];
	}
	read(0, buf, 1);
	if (buf[0] == '\n')
	{
		line[i] = '\0';
		return (check_instruction(line));
	}
	return (NULL);
}

t_instr	*read_input(t_stack *stacks)
{
	t_instr		*head;
	t_instr		*instr;
	void		(*func)(t_stack *);
	static char	buf[4];
	int			ret;

	head = NULL;
	while (1)
	{
		ret = read(0, buf, 3);
		if (ret == -1)
			error_handler(stacks, head);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		func = check_buffer(buf);
		instr = new_instr(func);
		if (!instr)
			error_handler(stacks, head);
		if (!head)
			head = instr;
		else
			add_node(head, instr);
	}
	return (head);
}
