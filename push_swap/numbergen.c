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

static void	gen_numbers(FILE *fptr, int count)
{
	while (count--)
	{
		fprintf(fptr, "%d\n", rand() % 1000);
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
