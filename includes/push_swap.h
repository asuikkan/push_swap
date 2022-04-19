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
	int	count_a;
	int	count_b;
}		t_stack;

void	error_handler(t_stack *stacks);
void	create_stacks(int argc, char **argv);

#endif
