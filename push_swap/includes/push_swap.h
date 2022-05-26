/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:02:56 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/26 15:02:58 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define LIMIT		2147483648
# define MAX_INTS	1000

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stack;

int		find_position(int *stack, int size, int value);
int		find_lowest(int *array, int size);
int		find_highest(int *stack, int size);
void	error_handler(t_stack *stacks);
void	sort_stack(t_stack *stacks);
void	push_a(t_stack *stacks);
void	push_b(t_stack *stacks);
void	swap_a(t_stack *stacks);
void	swap_b(t_stack *stacks);
void	swap_a_and_b(t_stack *stacks);
void	rotate_a(t_stack *stacks);
void	rotate_b(t_stack *stacks);
void	rotate_a_and_b(t_stack *stacks);
void	reverse_a(t_stack *stacks);
void	reverse_b(t_stack *stacks);
void	reverse_a_and_b(t_stack *stacks);
void	rotate_to_pos(t_stack *stacks, int *target);
t_stack	*create_stacks(int count, char **argv);

#endif
