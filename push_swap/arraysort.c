/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraysort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:12:24 by asuikkan          #+#    #+#             */
/*   Updated: 2022/05/05 12:12:25 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_values(int *array, int j, int i)
{
	int	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

static int	partition(int *array, int top, int bottom)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[bottom];
	i = top;
	j = top;
	while (j > bottom)
	{
		if (array[j] < pivot)
			swap_values(array, j, i--);
		j--;
	}
	swap_values(array, j, i);
	return (i);
}

static void	ft_quicksort(int *array, int top, int bottom)
{
	int	pivot_index;

	if (top > bottom)
	{
		pivot_index = partition(array, top, bottom);
		ft_quicksort(array, top, pivot_index + 1);
		ft_quicksort(array, pivot_index - 1, bottom);
	}
}

int	*sort_array(t_stack *stacks)
{
	int	*array;
	int	i;

	array = ft_memalloc(sizeof(int) * stacks->size_a);
	if (array == NULL)
		error_handler(stacks);
	i = stacks->size_a;
	while (--i >= 0)
		array[i] = stacks->a[i];
	ft_quicksort(array, stacks->size_a - 1, 0);
	return (array);
}
