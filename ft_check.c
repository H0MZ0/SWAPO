/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:39:28 by hakader           #+#    #+#             */
/*   Updated: 2025/01/28 19:10:36 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}

void	ft_isnum(char **av)
{
	int (i), (j);
	if (!av)
		exit(write (1, "Error\n", 6));
	j = 0;
	while (av[j])
	{
		i = 0;
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		while (av[j][i])
		{
			if (!(av[j][i] >= '0' && av[j][i] <= '9'))
				exit(write (1, "Error\n", 6));
			i++;
		}
		j++;
	}
}

int	strtoint(char **av, int **sorted)
{
	int (i), (size), (*arr);
	i = 0;
	size = 0;
	while (av[size])
		size++;
	arr = malloc(sizeof(int) * size);
	while (av[i])
	{
		arr[i] = ft_atoi(av[i]);
		i++;
	}
	*sorted = arr;
	return (size - 1);
}

void	ft_bubble(int *strs, int size)
{
	int (i), (j), (swapped);
	i = 1;
	while (i <= size)
	{
		j = i - 1;
		swapped = strs[i];
		while (j >= 0)
		{
			if (strs[j] > swapped)
			{
				strs[j + 1] = strs[j];
				strs[j] = swapped;
			}
			j--;
		}
		i++;
	}
}

void	ft_repeat(int **strs, int size)
{
	int (i), (*sorted);
	i = 0;
	sorted = *strs;
	while (i < size)
	{
		if (sorted[i] == sorted[i + 1])
		{
			write (1, "Error\n", 6);
			free(*strs);
			exit(1);
		}
		i++;
	}
}
