/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_retate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:00:09 by hakader           #+#    #+#             */
/*   Updated: 2025/02/18 19:52:00 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_ab(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (stack_is_empty(*stack) || (*stack)->next == NULL)
		return ;
	before_last = *stack;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}

void	rra(t_stack **stack_a, int check)
{
	ft_rev_rotate_ab(stack_a);
	if (check == 1)
		ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b, int check)
{
	ft_rev_rotate_ab(stack_b);
	if (check == 1)
		ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int check)
{
	ft_rev_rotate_ab(stack_a);
	ft_rev_rotate_ab(stack_b);
	if (check == 1)
		ft_putstr("rrr\n");
}
