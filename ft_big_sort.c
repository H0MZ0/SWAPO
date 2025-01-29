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

// void	last_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	while (*stack_b)
// 	{
// 		while (max_pos(stack_b) != 0)
// 			rrb(stack_b);
// 		if (max_pos(stack_b) == 0)
// 		{
// 			pa(stack_a, stack_b);
// 			(*stack_b) = (*stack_b)->next;
// 		}
// 		printf("stack_a\n");
// 		ft_printstack(*stack_a);
// 		printf("stack_b\n");
// 		ft_printstack(*stack_b);
// 		printf("max pos{{{{{{{{{%d}}}}}}}}}\n\n", max_pos(stack_b));
// 	}
// }

// void	ft_big_sort(t_stack **stack_a, int *sorted ,int size)
// {
// 	t_stack	*stack_b;
// 	int	start;
// 	int	end;
// 	int	range;

// 	range = get_range(size);
// 	start = 0;
// 	end = range;
// 	stack_b = NULL;
// 	// ft_printstack(*stack_a);
// 	printf("%d", min_pos(stack_a));
// 	// while (*stack_a)
// 	// {
// 	// 		// printf("hamza\n");
// 	// 	// if ((*stack_a)->content > sorted[end] && (*stack_a)->content >= 0)
// 	// 	// {
// 	// 	// 	while ((*stack_a)->content > 0)
// 	// 	// 	{
// 	// 	// 		if (min_pos(stack_a) > size / 2)
// 	// 	// 			ra(stack_a);
// 	// 	// 		else
// 	// 	// 			rra(stack_a);
// 	// 	// 	}
// 	// 	// 	printf("{{hola}}\n");
// 	// 	// }
// 	// 	if ((*stack_a)->content > sorted[end] && (*stack_a)->content < 0)
// 	// 	{
// 	// 		while ((*stack_a)->content < 0)
// 	// 		{
// 	// 			if (min_pos(stack_a) > size / 2)
// 	// 				rra(stack_a);
// 	// 			else
// 	// 				ra(stack_a);
// 	// 		}
// 	// 	}
// 	// 	if ((*stack_a)->content < sorted[start])
// 	// 	{
// 	// 		pb(stack_a, &stack_b);
// 	// 		rb(&stack_b);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		pb(stack_a, &stack_b);
// 	// 		if (stack_size(stack_b) > 0 && stack_b->content < stack_b->next->content)
// 	// 			sb(&stack_b);
// 	// 	}
// 	// 	(*stack_a) = (*stack_a)->next;
// 	// 	if (end < size)
// 	// 		end++;
// 	// 	if (end - start > 1)
// 	// 		start++;
// 	// }
// 	// last_sort(stack_a, &stack_b);
// 	// ft_printstack(*stack_a);
// }

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


// void	last_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*tmp;

// 	tmp = NULL;

// 	printf("..............\n");
// 	ft_printstack(*stack_b);
// 	printf("..............\n");
// 	while ((*stack_b))
// 	{
// 		while (get_max(*stack_b) != 0)
// 			rrb(stack_b);
// 		tmp = (*stack_b);
// 		if (get_max(*stack_b) == 0)
// 		{
// 			printf("%d\n", (*stack_b)->content);
// 			// free(tmp);
// 		}
// 			(*stack_b) = (*stack_b)->next;
// 	}
// }

t_stack	*last_sort(t_stack	*stack_b)
{
	t_stack	*stack_a;
	int index;

	stack_a = NULL;
	while (stack_b)
	{
		index = get_max(stack_b);
		if (index == 0)
		{
			printf("{{{%d}}}", index);
			push_stack(&stack_a, stack_b->content);
			printf("pa\n");
			stack_b = stack_b->next;
		}
		else
		{
			ft_rev_rotate_ab(&stack_b);
			printf ("rra\n");
		}
	}
	return (stack_a);
}

void	ft_big_sort(t_stack **stack_a, int *sorted ,int size)
{
	t_stack	*stack_b;
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
		if ((*stack_a)->content < sorted[start])
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
		(*stack_a) = (*stack_a)->next;
		if (end < size)
			end++;
		if (end - start > 1)
			start++;
		// printf(">>>>>>>>>>\n");
		// printf("\n<<<<<<<<<<");
	}
	*stack_a = last_sort(stack_b);
	ft_printstack(*stack_a);
}
