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

void	last_sort(t_stack	**stack_a, t_stack	**stack_b)
{
	printf("stack_b\n");
	// ft_printstack(*stack_b);
	while (*stack_b)
	{
		if (max_value(*stack_b) == (*stack_b)->content)
			{
				pa(stack_a, stack_b);
				(*stack_b) = (*stack_b)->next;
			}
		else
			rb(stack_b);
		// printf("\n{{{stack_a}}}\n");
		// ft_printstack(*stack_a);
		// printf("\n{{{stack_b}}}\n");
		// ft_printstack(*stack_b);
	}
	// ft_printstack(*stack_a);
}

void	ft_big_sort(t_stack **stack_a, int *sorted ,int size)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	int	start;
	int	end;
	int	range;

	range = get_range(size);
	start = 0;
	end = range;
	stack_b = NULL;
	while (*stack_a)
	{
			// printf("hamza\n");
				// printf("{{{{{%d}}}}}\n", min_pos(stack_a));
		while ((*stack_a)->content > sorted[end])
		{
			if (min_pos(stack_a) > size / 2)
				rra(stack_a);
		}
		if ((*stack_a)->content <= sorted[start])
		{
			pb(stack_a, &stack_b);
			rb(&stack_b);
		}
		else
		{
			pb(stack_a, &stack_b);
			if (stack_size(stack_b) > 0 && stack_b->content < stack_b->next->content)
				sb(&stack_b);
		}
		tmp = *stack_a;
		(*stack_a) = (*stack_a)->next;
		free(tmp);
		if (end < size)
			end++;
		if (end - start > 1)
			start++;
	}
	// free_int(sorted, size);
	// free(sorted);
	last_sort(stack_a, &stack_b);
	// ft_printstack(stack_b);
}
