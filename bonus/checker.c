/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:08:51 by hakader           #+#    #+#             */
/*   Updated: 2025/02/03 12:45:14 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*skip_spaces(char *str)
{
	char *dest;
	int	i;
	int	j;

	dest = NULL;
	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == 32 && str[i])
			i++;
		else
			dest[j] = str[i];
		i++;
		j++;
	}
	return (dest);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	// while (s1[i] == 32)
	// 	i++;
	while ((s1[i] || s2[j]))
	{
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		i++;
		j++;
	}
	return (0);
}

void	get_checker(t_stack **stack_a, t_stack **stack_b, char *get)
{
	if (ft_strcmp(get, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(get, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(get, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(get, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(get, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(get, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(get, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(get, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(get, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(get, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(get, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(get, "rrr\n") == 0)
		(rrr(stack_a, stack_b, 0));
	else
	{
		free_struct(stack_a);
		free_struct(stack_b);
		free(get);
		put_err("Error\n");
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*get;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	get = NULL;
	if (ac < 2)
		exit (1);
	ac = ac - 1;
	filter(ac, av, &stack_a, 0);
	size = stack_size(stack_a);
	while ((get = get_next_line(0)))
	{
		get = skip_spaces(get);
		printf("{{%s}}\n", get);
		get_checker (&stack_a, &stack_b, get);
		free (get);
	}
	ft_printstack(stack_a);
	if (check_sort(stack_a) == 0 && stack_size(stack_a) == size)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_struct(&stack_a);
}
