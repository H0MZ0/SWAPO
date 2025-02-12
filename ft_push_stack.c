/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:12 by hakader           #+#    #+#             */
/*   Updated: 2025/02/12 13:16:12 by hakader          ###   ########.fr       */
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

void	pa(t_stack **stack_a, t_stack **stack_b, int check)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (stack_is_empty(*stack_b))
		return ;
	push_stack(stack_a, (*stack_b)->content);
	(*stack_b) = (*stack_b)->next;
	free (tmp);
	if (check == 1)
		ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int check)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (stack_is_empty(*stack_a))
		return ;
	push_stack(stack_b, (*stack_a)->content);
	(*stack_a) = (*stack_a)->next;
	free (tmp);
	if (check == 1)
		ft_putstr("pb\n");
}

void	ft_printstack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	printf("%d\n", stack->content);
	ft_printstack(stack->next);
}
