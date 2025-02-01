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

int	check_sort(t_stack	*stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	last_pb(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	if (stack_size(*stack_b) > 0)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);
	}
}

void	ft_big_sort(t_stack **stack_a, int *sorted, int size)
{
	t_stack	*stack_b;
	int		range;
	int		index;

	range = get_range(size);
	index = 0;
	stack_b = NULL;
	while (*stack_a)
	{
		if ((range + index) >= size)
			range = size - index;
		if ((*stack_a)->content >= sorted[index]
			&& (*stack_a)->content <= sorted[range + index])
			(last_pb(stack_a, &stack_b)), (index++);
		else if ((*stack_a)->content < sorted[index])
			(pb(stack_a, &stack_b)), (rb(&stack_b)), (index++);
		else
			ra(stack_a);
	}
	last_sort(stack_a, &stack_b);
}

void	last_sort(t_stack	**stack_a, t_stack	**stack_b)
{
	int	max;
	int	max_posi;

	while (*stack_b)
	{
		max = max_value(*stack_b);
		max_posi = max_pos(stack_b);
		if (max_posi <= stack_size(*stack_b) / 2)
		{
			while (max != (*stack_b)->content)
				rb(stack_b);
		}
		else if (max_posi > stack_size(*stack_b) / 2)
		{
			while (max != (*stack_b)->content)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
