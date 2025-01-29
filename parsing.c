/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:37:46 by hakader           #+#    #+#             */
/*   Updated: 2025/01/29 11:28:17 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_spaces(char **av)
{
	int (i), (j);
	i = 1;
	if (!av)
		exit(write (1, "Error\n", 6));
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
			exit(write (1, "Error\n", 6));
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

void	filter(int ac, char **av)
{
	char	*arr;
	t_stack	*stack_a;
	int		size;
	int		*sorted;

	stack_a = NULL;
	if (ac <= 1)
		exit (1);
	check_spaces(av);
	arr = join_args(av);
	av = ft_split(arr, ' ');
	ft_isnum(av);
	ac = ac - 1;
	while (ac--)
		push_stack(&stack_a, ft_atoi(av[ac]));
	size = strtoint(av, &sorted);
	ft_bubble(sorted, size);
	ft_repeat(&sorted, size);
	ft_range(stack_a, sorted, size);
}
