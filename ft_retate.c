/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:57:12 by hakader           #+#    #+#             */
/*   Updated: 2025/02/02 22:31:13 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_ab(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	if (stack_is_empty(*stack))
		return ;
	while (last->next)
		last = last->next;
	last->next = (*stack);
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack **stack_a, int check)
{
	ft_rotate_ab(stack_a);
	if (check == 1)
		ft_putstr("ra\n");
}

void	rb(t_stack **stack_b, int check)
{
	ft_rotate_ab(stack_b);
	if (check == 1)
		ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int check)
{
	ft_rotate_ab(stack_a);
	ft_rotate_ab(stack_b);
	if (check == 1)
		ft_putstr("rr\n");
}

void	ft_rotate_to_top(t_stack **stack_a, int index, int size)
{
	if (index != 0)
	{
		if (index <= size / 2)
			while (index--)
				ra(stack_a, 1);
		else
		{
			index = size - index;
			while (index--)
				rra(stack_a, 1);
		}
	}
}
