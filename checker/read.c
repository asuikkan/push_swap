/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:40:57 by asuikkan          #+#    #+#             */
/*   Updated: 2022/05/11 14:40:59 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <fcntl.h>

static t_stack	*initialize(int count)
{
	t_stack	*stacks;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	if (stacks == NULL)
		error_handler(stacks, NULL);
	stacks->a = ft_memalloc(sizeof(int) * count);
	stacks->b = ft_memalloc(sizeof(int) * count);
	if (stacks->a == NULL || stacks->b == NULL)
		error_handler(stacks, NULL);
	stacks->size_a = count;
	stacks->size_b = 0;
	return (stacks);
}

static void	copy_temp(int *stack, int temp_stack[MAX_INTS], int count)
{
	int	i;
	int	j;

	i = 0;
	j = count - 1;
	while (i < count - 1)
		stack[j--] = temp_stack[i++];
}

static int	validate_line(int temp_stack[MAX_INTS], int count, char *line)
{
	int		i;
	int		sign;
	long	value;

	sign = 1;
	value = 0;
	i = 0;
	if (line[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		value = value * 10 + (line[i++] - '0');
		if ((value == LIMIT && sign == 1) || value > LIMIT)
			return (0);
	}
	value *= sign;
	temp_stack[count] = value;
	return (1);
}

t_stack	*read_file(char	*file)
{
	int		fd;
	int		count;
	int		temp_stack[MAX_INTS];
	char	*line;
	t_stack	*stacks;

	stacks = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!validate_line(temp_stack, count, line))
			error_handler(stacks, NULL);
		free(line);
		count++;
	}
	stacks = initialize(count);
	copy_temp(stacks->a, temp_stack, count);
	return (stacks);
}
