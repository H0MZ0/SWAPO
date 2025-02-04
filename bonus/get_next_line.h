/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:21:53 by hakader           #+#    #+#             */
/*   Updated: 2025/02/04 10:50:07 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*get_line(int fd, char **full_buff);
char	*ft_handle(char **full_buff, int new_line_index);
void	ft_free(char **str);
int		ft_charlen(char *str);
size_t	ft_strlenn(const char *str);
char	*ft_strdupp(const char *s1);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_substrr(char const *s, unsigned int start, size_t len);
size_t	ft_minn(size_t a, size_t b);

#endif
