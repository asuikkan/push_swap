/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:08:35 by asuikkan          #+#    #+#             */
/*   Updated: 2022/05/26 12:08:37 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest(int *stack, int size)
{
	int	i;
	int	max;
	int	max_i;

	i = size - 1;
	max_i = i;
	max = stack[max_i];
	while (--i >= 0)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			max_i = i;
		}
	}
	return (max_i);
}

int	find_lowest(int *array, int size)
{
	int	lowest;
	int	i;

	i = 0;
	lowest = array[i];
	while (++i < size)
	{
		if (array[i] < lowest)
			lowest = array[i];
	}
	return (lowest);
}

int	find_position(int *stack, int size, int value)
{
	int	start;
	int	i;

	start = find_highest(stack, size);
	if (value > stack[start])
		return (start);
	i = start;
	while (--i != start)
	{
		if (i == -1)
			i = size;
		else if (i == size - 1)
		{
			if (stack[i] < value && stack[0] > value)
				return (i);
		}
		else
		{
			if (stack[i] < value && stack[i + 1] > value)
				return (i);
		}
	}
	return (start);
}
