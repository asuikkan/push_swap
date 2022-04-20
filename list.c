/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:08:53 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/20 15:08:55 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instr	*new_instr(void (*func)(t_stack *))
{
	t_instr	*new;

	new = (t_instr *)malloc(sizeof(t_instr));
	if (!new)
		return (NULL);
	new->func = func;
	new->next = NULL;
	return (new);
}
