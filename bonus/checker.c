/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:08:51 by hakader           #+#    #+#             */
/*   Updated: 2025/02/02 23:37:25 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_checker(t_stack **stack_a, t_stack **stack_b, char *get)
{
	if (strcmp(get, " sa\n") == 0)
		sa(stack_a, 0);
	else if (strcmp(get, " sb\n") == 0)
		sb(stack_b, 0);
	else if (strcmp(get, " ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else if (strcmp(get, " pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (strcmp(get, " pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (strcmp(get, " sb\n") == 0)
		sb(stack_b, 0);
	else if (strcmp(get, " ra\n") == 0)
		ra(stack_a, 0);
	else if (strcmp(get, " rb\n") == 0)
		rb(stack_b, 0);
	else if (strcmp(get, " rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (strcmp(get, " rra\n") == 0)
		rra(stack_a, 0);
	else if (strcmp(get, " rrb\n") == 0)
		rrb(stack_b, 0);
	else if (strcmp(get, " rrr\n") == 0)
		(rrr(stack_a, stack_b, 0));
	else
	{
		free_struct(stack_a);
		free_struct(stack_b);
		free(get);
		put_err("Error\n");
	}
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char *get;

	stack_a = NULL;
	stack_b = NULL;
	get = NULL;
	if (ac < 2)
		exit (1);
	ac = ac - 1;
	filter(ac, av, &stack_a, 0);
	while ((get = get_next_line(0)))
	{
		get_checker (&stack_a, &stack_b, get);
		free (get);
	}
	if (check_sort(stack_a) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_struct(&stack_a);
}
