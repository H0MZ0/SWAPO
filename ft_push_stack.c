/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:12 by hakader           #+#    #+#             */
/*   Updated: 2025/01/29 19:32:22 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_creat_stack(int data)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->content = data;
	new_stack->next = NULL;
	return (new_stack);
}

int	push_stack(t_stack **stack, int data)
{
	t_stack	*new_stack;

	new_stack = ft_creat_stack(data);
	if (!new_stack)
		return (0);
	new_stack->next = *stack;
	*stack = new_stack;
	return (1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_a, (*stack_b)->content);
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_b, (*stack_a)->content);
	ft_putstr("pb\n");
}
