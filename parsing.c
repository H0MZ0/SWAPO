/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:37:46 by hakader           #+#    #+#             */
/*   Updated: 2025/02/01 12:18:24 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_spaces(char **av)
{
	int (i), (j);
	i = 1;
	if (!av)
	{
		ft_putstr("Error\n");
		exit (1);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != 32)
				break ;
			j++;
		}
		if (av[i][j] == '\0')
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
}

char	*join_args(char **av)
{
	int		i;
	char	*join;
	char	*tmp;

	i = 1;
	join = NULL;
	while (av[i])
	{
		tmp = join;
		join = ft_strjoin(join, av[i]);
		if (tmp)
			free(tmp);
		i++;
	}
	return (join);
}

void	free_repeat(t_stack *stack, int *sorted, char **av)
{
	free_struct(stack);
	free(sorted);
	free_arr(av);
	ft_putstr("Error\n");
}

void	filter(int ac, char **av)
{
	char	*arr;
	t_stack	*stack_a;
	int		size;
	int		*sorted;

	size = 0;
	arr = NULL;
	stack_a = NULL;
	check_spaces(av);
	arr = join_args(av);
	av = ft_split(arr, ' ');
	while (av[size])
		size++;
	free(arr);
	if (ft_isnum(av) == 0)
		(free_arr(av)), (ft_putstr ("Error\n"));
	ac = ac - 1;
	while (size--)
		push_stack(&stack_a, ft_atoi(av[size]));
	size = strtoint(av, &sorted);
	ft_bubble(sorted, size);
	if (ft_repeat(&sorted, size) == 0)
		free_repeat(stack_a, sorted, av);
	free_arr(av);
	ft_range(&stack_a, sorted, size);
}
