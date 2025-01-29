/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:15:32 by hakader           #+#    #+#             */
/*   Updated: 2025/01/29 11:45:15 by hakader          ###   ########.fr       */
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
		return (3);
	else if (size <= 100)
		return (16);
	else if (size <= 500)
		return (30);
	else
		return (35);
}

void	range_three(t_stack **stack_a)
{
	if (min_pos(stack_a) == 1 && max_pos(stack_a) == 2)
		sa(stack_a);
	if (min_pos(stack_a) == 0 && max_pos(stack_a) == 1)
		sa(stack_a);
	if (min_pos(stack_a) == 1 && max_pos(stack_a) == 0)
		ra(stack_a);
	if (min_pos(stack_a) == 2 && max_pos(stack_a) == 0)
		sa(stack_a);
	if (min_pos(stack_a) == 2 && max_pos(stack_a) == 1)
		rra(stack_a);
}

void	range_tofive(t_stack **stack_a, int size)
{
	int		tmp;
	t_stack	*stack_b;

	stack_b = NULL;
	tmp = size;
	while (size != 2)
	{
		while (min_pos(stack_a) != 0)
			ra(stack_a);
		pb(stack_a, &stack_b);
		(*stack_a) = (*stack_a)->next;
		size--;
	}
	range_three(stack_a);
	tmp = tmp - size - 1;
	while (tmp >= 0)
	{
		pa(stack_a, &stack_b);
		stack_b = stack_b->next;
		tmp--;
	}
}

void	ft_range(t_stack *stack_a, int *sorted, int size)
{
	int	check;
	int	range;

	range = get_range(size);
	check = min_pos(&stack_a);
	if (size == 1)
		if (check != 0)
			sa(&stack_a);
	if (size == 2)
		range_three(&stack_a);
	if (size == 3 || size == 4)
		range_tofive(&stack_a, size);
	else
		ft_big_sort(&stack_a, sorted, size);
	// ft_printstack(stack_a);
}
