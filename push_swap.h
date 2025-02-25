/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:19:08 by hakader           #+#    #+#             */
/*   Updated: 2025/02/05 12:18:35 by hakader          ###   ########.fr       */
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
void	sa(t_stack **stack_a, int check);
void	sb(t_stack **stack_b, int check);
void	ss(t_stack **stack_a, t_stack **stack_b, int check);
/*PUSH*/
t_stack	*ft_creat_stack(int data);
int		push_stack(t_stack **stack, int data);
void	pa(t_stack **stack_a, t_stack **stack_b, int check);
void	pb(t_stack **stack_a, t_stack **stack_b, int check);
/*RETATE*/
void	ft_rotate_ab(t_stack **stack);
void	ra(t_stack **stack_a, int check);
void	rb(t_stack **stack_b, int check);
void	rr(t_stack **stack_a, t_stack **stack_b, int check);
void	ft_rotate_to_top(t_stack **stack_a, int index, int size);
/*REVERSE_RETATE*/
void	ft_rev_rotate_ab(t_stack **stack);
void	rra(t_stack **stack_a, int check);
void	rrb(t_stack **stack_b, int check);
void	rrr(t_stack **stack_a, t_stack **stack_b, int check);
/*FT_FREE*/
void	free_struct(t_stack **stack);
void	free_arr(char **arr);
void	put_err(char *str);
/*PARSING_and_FILTER*/
int		ft_strcmp(const char *s1, const char *s2);
void	filter(int ac, char **av, t_stack **stack_a, int check);
void	check_spaces(char **av);
char	*join_args(char **av);
char	**ft_split(char const *s, char c);
/*INT*_CHECK*/
int		stack_is_empty(t_stack *stack);
int		ft_isnum(char **av);
int		strtoint(char **av, int **sorted);
void	ft_bubble(int *strs, int size);
int		ft_repeat(int **strs, int size);
/*RANGE*/
int		stack_size(t_stack *stack);
int		get_range(int size);
void	ft_range(t_stack **stack_a, int *sorted, int size);
void	range_three(t_stack **stack_a);
void	range_tofive(t_stack **stack_a, int size);
/*BIG_SORT*/
void	ft_big_sort(t_stack **stack_a, int *sorted, int size);
void	last_pb(t_stack **stack_a, t_stack **stack_b);
void	last_sort(t_stack	**stack_a, t_stack	**stack_b);
int		check_sort(t_stack	*stack_a);
/*POS_and_VALUE*/
int		min_pos(t_stack **stack_a);
int		max_pos(t_stack **stack_a);
int		max_value(t_stack *stack_a);
int		ft_atoi(char *str);
/*HELPERS*/
int		ft_atoio(char *str, char **av, t_stack **stack);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr(char *str);
/*STACK*/
void	ft_printstack(t_stack *stack);

#endif