/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:01:37 by hakader           #+#    #+#             */
/*   Updated: 2025/01/26 11:01:37 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int max;
	int	index;
	int i;

	i = 0;
	max = stack->content;
	index = 0;
	stack = (stack->next);
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	get_min(t_stack *stack)
{
	int min;
	int	index;
	int i;

	i = 0;
	min = stack->content;
	index = 0;
	stack = (stack->next);
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}
void	ft_big_sort(t_stack **stack_a, int *sorted, int size)
{
	t_stack	*stack_b;
	stack_b = NULL;

	int range = get_range(size);
	int index = 0;

	while (*stack_a)
	{
		if ((range + index) >= size)
			range = size - index;
		if ((*stack_a)->content >= sorted[index] && (*stack_a)->content <= sorted[range + index])
		{
			pb(stack_a, &stack_b);
			if (stack_size(stack_b) > 0)
			{
				if (stack_b->content < stack_b->next->content)
					sb(&stack_b);
				index++;
			}
		}
		else if ((*stack_a)->content < sorted[index])
		{
			pb(stack_a, &stack_b);
			rb(&stack_b);
			index++;
		}
		else
			ra(stack_a);
	}
	last_sort(stack_a, &stack_b);
}

void	last_sort(t_stack	**stack_a, t_stack	**stack_b)
{
	int max;
	int max_pos;

	while (*stack_b)
	{
		max = max_value(*stack_b);
		max_pos = get_max(*stack_b);
		if (max_pos <= stack_size(*stack_b) / 2)
		{
			while (max != (*stack_b)->content)
				rb(stack_b);
		}
		else if (max_pos > stack_size(*stack_b) / 2)
		{
			while (max != (*stack_b)->content)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
	ft_printstack(*stack_a);
}
