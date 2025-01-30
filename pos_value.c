/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:07:29 by hakader           #+#    #+#             */
/*   Updated: 2025/01/30 11:50:14 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack **stack_a)
{
	t_stack	*tmp;

	int (min), (index), (i);
	i = 0;
	index = 0;
	tmp = (*stack_a);
	min = tmp->content;
	while (tmp != NULL)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	max_pos(t_stack **stack_a)
{
	t_stack	*tmp;

	int max;
	int	index;
	int i;

	i = 0;
	tmp = (*stack_a);
	max = tmp->content;
	index = 0;
	while (tmp != NULL)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	max_value(t_stack *stack)
{
	int max;

	max = stack->content;
	stack = (stack->next);
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
