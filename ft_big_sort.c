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

// void	last_sort(t_stack	**stack_a, t_stack	**stack_b)
// {
// 	// int size = stack_size();
// 	while (*stack_b)
// 	{
// 		while (get_max(*stack_b) == 0)
// 		{
// 			pa(stack_a, stack_b);
// 			(*stack_b) = (*stack_b)->next;
// 		}
// 		if (get_max(*stack_b) > stack_size(*stack_b) / 2)
// 			rrb(stack_b);
// 		else if (get_max(*stack_b) <= stack_size(*stack_b) / 2)
// 			rb(stack_b);
// 		(*stack_b) = (*stack_b)->next;
// 	}
// }

void	last_sort(t_stack	**stack_a, t_stack	**stack_b)
{
	int max_index;
	int size_b;

	while (*stack_b)
	{
		max_index = get_max(*stack_b);
		size_b = stack_size(*stack_b);

		if (max_index == 0)
		{
			pa(stack_a, stack_b);
			(*stack_b) = (*stack_b)->next;
		}
		else
		{
			if (max_index > size_b / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}
	}
}

void	ft_big_sort(t_stack **stack_a, int *sorted, int size)
{
	t_stack	*stack_b;
	int start, end, range;

	start = 0;
	range = get_range(size);
	end = range;
	stack_b = NULL;
	while (*stack_a)
	{
		while ((*stack_a)->content > sorted[end])
		{
			if (get_min(*stack_a) == 0)
			{
				pb(stack_a, &stack_b);
				(*stack_a) = (*stack_a)->next;
			}
			if (get_min(*stack_a) > range / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
		if ((*stack_a)->content < sorted[start])
		{
			pb(stack_a, &stack_b);
			if (stack_size(stack_b) > 0)
				rb(&stack_b);
		}
		else
			pb(stack_a, &stack_b);
		(*stack_a) = (*stack_a)->next;
		start++;
		if (end < size)
			end++;
	}
	last_sort(stack_a, &stack_b);
	// ft_printstack(*stack_a);
}
