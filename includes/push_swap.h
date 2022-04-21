/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:16:38 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/15 16:16:39 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LIMIT	2147483648

# include "libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	top_a;
	int	top_b;
}		t_stack;

typedef struct s_instr
{
	void			(*func)(t_stack *);
	struct s_instr	*next;
}					t_instr;


void	error_handler(t_stack *stacks, t_instr *cmds);
void	swap_a(t_stack *stacks);
void	swap_b(t_stack *stacks);
void	swap_a_and_b(t_stack *stacks);
void	push_a(t_stack *stacks);
void	push_b(t_stack *stacks);
void	push_a_and_b(t_stack *stacks);
void	execute_cmds(t_stack *stacks, t_instr *cmds);
t_stack	*create_stacks(int argc, char **argv);
t_instr	*read_input(t_stack *stacks);
t_instr	*new_instr(void (*func)(t_stack *));

#endif
