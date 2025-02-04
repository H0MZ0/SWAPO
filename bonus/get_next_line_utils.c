/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:58:10 by hakader           #+#    #+#             */
/*   Updated: 2025/02/04 10:48:07 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdupp(const char *s1)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlenn(s1);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!result)
		return (ft_strdupp(""));
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	if (s1)
		ft_free(&s1);
	return (result);
}

size_t	ft_minn(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substrr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlenn(s);
	if (start >= s_len)
		return (ft_strdupp(""));
	len = ft_minn(len, s_len - start);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
