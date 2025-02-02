/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:24:21 by hakader           #+#    #+#             */
/*   Updated: 2025/02/02 20:35:12 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_struct(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}


void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (i--)
		free(arr[i]);
	free (arr);
}

void	put_err(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
		write (2, &str[i++], 1);
	if (strcmp(str, "Error\n") == 0)
		exit (1);
}
