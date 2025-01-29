/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:37:30 by hakader           #+#    #+#             */
/*   Updated: 2025/01/28 19:19:28 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printstack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	printf("%d\n", stack->content);
	ft_printstack(stack->next);
}

int	main(int ac, char **av)
{
	filter(ac, av);
}
