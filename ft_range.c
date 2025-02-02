/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:15:32 by hakader           #+#    #+#             */
/*   Updated: 2025/02/02 22:35:27 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_range(int size)
{
	if (size <= 16)
		return (size / 2);
	else if (size <= 100)
		return (size / 5);
	else if (size <= 500)
		return (size / 12);
	else
		return (35);
}

void	range_three(t_stack **stack_a)
{
	if (min_pos(stack_a) == 1 && max_pos(stack_a) == 2)
		sa(stack_a, 1);
	if (min_pos(stack_a) == 0 && max_pos(stack_a) == 1)
		sa(stack_a, 1);
	if (min_pos(stack_a) == 1 && max_pos(stack_a) == 0)
		ra(stack_a, 1);
	if (min_pos(stack_a) == 2 && max_pos(stack_a) == 0)
		sa(stack_a, 1);
	if (min_pos(stack_a) == 2 && max_pos(stack_a) == 1)
		rra(stack_a, 1);
}

void	range_tofive(t_stack **stack_a, int size)
{
	int		tmp;
	t_stack	*stack_b;

	stack_b = NULL;
	tmp = size;
	while (size != 2)
	{
		ft_rotate_to_top(stack_a, min_pos(stack_a), size + 1);
		pb(stack_a, &stack_b, 1);
		size--;
	}
	range_three(stack_a);
	tmp = tmp - size - 1;
	while (tmp >= 0)
	{
		pa(stack_a, &stack_b, 1);
		tmp--;
	}
}

void	ft_range(t_stack **stack_a, int *sorted, int size)
{
	int	check;

	check = min_pos(stack_a);
	if (check_sort(*stack_a) == 1)
	{
		if (size == 1)
			if (check != 0)
				sa(stack_a, 1);
		if (size == 2)
			range_three(stack_a);
		if (size == 3 || size == 4)
			range_tofive(stack_a, size);
		if (size > 4)
			ft_big_sort(stack_a, sorted, size);
	}
	free (sorted);
	// ft_printstack(*stack_a);
	free_struct(stack_a);
}
