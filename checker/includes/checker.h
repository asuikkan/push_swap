/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:16:38 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/15 16:16:39 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define LIMIT		2147483648
# define MAX_INTS	1000

# include "libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
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
void	rotate_a(t_stack *stacks);
void	rotate_b(t_stack *stacks);
void	rotate_a_and_b(t_stack *stacks);
void	reverse_a(t_stack *stacks);
void	reverse_b(t_stack *stacks);
void	reverse_a_and_b(t_stack *stacks);
void	execute_cmds(t_stack *stacks, t_instr *cmds);
void	(*check_swap(char *line))(t_stack *);
void	(*check_push(char *line))(t_stack *);
void	(*check_rotate(char *line))(t_stack *);
void	(*check_reverse(char *line))(t_stack *);
t_stack	*create_stacks(int argc, char **argv);
t_stack	*read_file(char	*file);
t_instr	*read_input(t_stack *stacks);
t_instr	*new_instr(void (*func)(t_stack *));

#endif
