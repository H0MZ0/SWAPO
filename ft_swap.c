/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:41:09 by hakader           #+#    #+#             */
/*   Updated: 2025/02/02 22:27:21 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack **stack)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	sa(t_stack **stack_a, int check)
{
	swap_ab(stack_a);
	if (check == 1)
		ft_putstr("sa\n");
}

void	sb(t_stack **stack_b, int check)
{
	swap_ab(stack_b);
	if (check == 1)
		ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int check)
{
	swap_ab(stack_a);
	swap_ab(stack_b);
	if (check == 1)
		ft_putstr("ss\n");
}
