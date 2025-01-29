/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:19:08 by hakader           #+#    #+#             */
/*   Updated: 2025/01/29 19:48:15 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct list
{
	int			content;
	struct list	*next;
}	t_stack;

/*SWAP*/
void	swap_ab(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
/*PUSH*/
t_stack	*ft_creat_stack(int data);
int		push_stack(t_stack **stack, int data);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
/*RETATE*/
void	ft_rotate_ab(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/*REVERSE_RETATE*/
void	ft_rev_rotate_ab(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/*FT_FREE*/
void	free_struct(t_stack *stack);
void	free_arr(char **arr);
/*PARSING_and_FILTER*/
void	filter(int ac, char **av);
void	check_spaces(char **av);
char	*join_args(char **av);
char	**ft_split(char const *s, char c);
/*INT*_CHECK*/
int		stack_is_empty(t_stack *stack);
void	ft_isnum(char **av);
int		strtoint(char **av, int **sorted);
void	ft_bubble(int *strs, int size);
void	ft_repeat(int **strs, int size);
/*RANGE*/
int		stack_size(t_stack *stack);
int		get_range(int size);
void	ft_range(t_stack *stack_a, int *sorted, int size);
void	range_three(t_stack **stack_a);
void	range_tofive(t_stack **stack_a, int size);
/*BIG_SORT*/
void	ft_big_sort(t_stack **stack_a, int *sorted, int size);
t_stack	*last_sort(t_stack *stack_b);
/*POS_and_VALUE*/
int		min_pos(t_stack **stack_a);
int		max_pos(t_stack **stack_a);
int		mini(t_stack **stack_a);
int		maxi(t_stack **stack_a);
/*HELPERS*/
int		ft_atoi(char *str);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr(char *str);
/*STACK*/
void	ft_printstack(t_stack *stack);






int	max_value(t_stack *stack_a);

#endif