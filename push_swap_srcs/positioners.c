/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:12:39 by asuikkan          #+#    #+#             */
/*   Updated: 2022/05/26 12:12:41 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotater(t_stack *stacks, int target_i, int pos)
{
	int	val_a;
	int	val_b;

	val_a = stacks->a[target_i];
	val_b = stacks->b[pos];
	if (stacks->size_a - 1 - target_i >= stacks->size_b - 1 - pos)
	{
		while (stacks->b[stacks->size_b - 1] != val_b)
			rotate_a_and_b(stacks);
		while (stacks->a[stacks->size_a - 1] != val_a)
			rotate_a(stacks);
	}
	else
	{
		while (stacks->a[stacks->size_a - 1] != val_a)
			rotate_a_and_b(stacks);
		while (stacks->b[stacks->size_b - 1] != val_b)
			rotate_b(stacks);
	}
}

static void	reverser(t_stack *stacks, int target_i, int pos)
{
	int	val_a;
	int	val_b;

	val_a = stacks->a[target_i];
	val_b = stacks->b[pos];
	if (target_i + 1 >= pos + 1)
	{
		while (stacks->b[stacks->size_b - 1] != val_b)
			reverse_a_and_b(stacks);
		while (stacks->a[stacks->size_a - 1] != val_a)
			reverse_a(stacks);
	}
	else
	{
		while (stacks->a[stacks->size_a - 1] != val_a)
			reverse_a_and_b(stacks);
		while (stacks->b[stacks->size_b - 1] != val_b)
			reverse_b(stacks);
	}
}

static void	rot_rev(t_stack *stacks, int target_i, int pos)
{
	int	val_a;
	int	val_b;

	val_a = stacks->a[target_i];
	val_b = stacks->b[pos];
	if (target_i >= (stacks->size_a - 1) / 2)
	{
		while (stacks->a[stacks->size_a - 1] != val_a)
			rotate_a(stacks);
	}
	else
	{
		while (stacks->a[stacks->size_a - 1] != val_a)
			reverse_a(stacks);
	}
	if (pos >= (stacks->size_b - 1) / 2)
	{
		while (stacks->b[stacks->size_b - 1] != val_b)
			rotate_b(stacks);
	}
	else
	{
		while (stacks->b[stacks->size_b - 1] != val_b)
			reverse_b(stacks);
	}
}

void	rotate_to_pos(t_stack *stacks, int *target)
{
	int	pos;

	pos = find_position(stacks->b, stacks->size_b, stacks->a[target[3]]);
	if (target[0] <= target[1] && target[0] <= target[2])
		rotater(stacks, target[3], pos);
	else if (target[1] <= target[0] && target[1] <= target[2])
		reverser(stacks, target[3], pos);
	else
		rot_rev(stacks, target[3], pos);
}
