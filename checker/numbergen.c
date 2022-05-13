/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbergen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:38:14 by asuikkan          #+#    #+#             */
/*   Updated: 2022/05/11 11:38:16 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int	check_duplicate(int nb, int array[1000], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (array[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

static void	gen_numbers(FILE *fptr, int count)
{
	int			array[1000];
	int			nb;
	static int	i;

	i = 0;
	while (count)
	{
		nb = rand() % 1000;
		if (!check_duplicate(nb, array, i))
			continue ;
		else
		{
			array[i] = nb;
			i++;
			fprintf(fptr, "%d", nb);
			if (count != 1)
				fprintf(fptr, " ");
			count--;
		}
	}
}

int	main(void)
{
	FILE	*fptr;
	int		count;

	fptr = fopen("numbers.txt", "w");
	if (fptr == NULL)
	{
		printf("Open error\n");
		return (0);
	}
	printf("How many numbers? 1-1000\n");
	scanf("%d", &count);
	if (count <= 0 || count > 1000)
	{
		printf("Invalid input\n");
		return (0);
	}
	gen_numbers(fptr, count);
	return (0);
}
