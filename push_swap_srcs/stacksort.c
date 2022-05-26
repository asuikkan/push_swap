/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:24:30 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/28 14:24:31 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(t_stack *stacks)
{
	int	count;
	int	rotate;
	int	max_count;
	int	max_rotate;

	count = 0;
	rotate = 0;
	max_rotate = stacks->size_a;
	max_count = stacks->size_a + stacks->size_b;
	while (stacks->size_b > 0)
	{
		if (stacks->a[0] > stacks->b[stacks->size_b - 1] && rotate < max_rotate)
		{
			reverse_a(stacks);
			rotate++;
		}
		else
			push_a(stacks);
		count++;
	}
	while (count++ < max_count)
		reverse_a(stacks);
}

static int	*count_moves(t_stack *stacks, int i, int pos)
{
	static int	temp[3];

	if (stacks->size_a - 1 - i >= stacks->size_b - 1 - pos)
		temp[0] = stacks->size_a - 1 - i;
	else
		temp[0] = stacks->size_b - 1 - pos;
	if (i + 1 >= pos + 1)
		temp[1] = i + 1;
	else
		temp[1] = pos + 1;
	if (stacks->size_a - 1 - i >= stacks->size_b - 1 - pos)
		temp[2] = i + 1 + stacks->size_b - 1 - pos;
	else
		temp[2] = pos + 1 + stacks->size_a - 1 - i;
	return (temp);
}

static int	*find_target(t_stack *stacks)
{
	static int	target[4];
	int			*temp;
	int			i;
	int			j;
	int			pos;

	i = 0;
	while (i < 4)
		target[i++] = 10000;
	i = stacks->size_a;
	while (--i >= 0)
	{
		pos = find_position(stacks->b, stacks->size_b, stacks->a[i]);
		temp = count_moves(stacks, i, pos);
		if (find_lowest(temp, 3) < find_lowest(target, 3))
		{
			j = -1;
			while (++j < 3)
				target[j] = temp[j];
			target[3] = i;
		}
	}
	return (target);
}

static void	pusher(t_stack *stacks)
{
	int	*target;

	while (stacks->size_b < 2)
		push_b(stacks);
	while (stacks->size_a > 3)
	{
		target = find_target(stacks);
		rotate_to_pos(stacks, target);
		push_b(stacks);
	}
	sort_small(stacks);
	reset_b(stacks);
}

void	sort_stack(t_stack *stacks)
{
	if (is_sorted(stacks->a, stacks->size_a))
		return ;
	if (stacks->size_a < 4)
		sort_small(stacks);
	else
	{
		pusher(stacks);
		merge(stacks);
	}
}
