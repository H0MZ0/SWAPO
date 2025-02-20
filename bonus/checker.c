/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:08:51 by hakader           #+#    #+#             */
/*   Updated: 2025/02/20 09:52:29 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	handle_error(t_stack **stack_a, t_stack **stack_b, char *get)
{
	free(get);
	free_struct(stack_a);
	free_struct(stack_b);
	get_next_line(10);
	put_err("Error\n");
}

void	get_check(t_stack **stack_a, t_stack **stack_b, char *get)
{
	if (!ft_strcmp(get, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(get, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(get, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(get, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(get, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(get, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(get, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(get, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(get, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(get, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(get, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else
		handle_error(stack_a, stack_b, get);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*get;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit (0);
	ac = ac - 1;
	filter(ac, av, &stack_a, 0);
	size = stack_size(stack_a);
	get = get_next_line(0);
	while (get)
	{
		get_check (&stack_a, &stack_b, get);
		free (get);
		get = get_next_line(0);
	}
	if (check_sort(stack_a) == 0 && stack_size(stack_a) == size)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_struct(&stack_a);
	free_struct(&stack_b);
}
