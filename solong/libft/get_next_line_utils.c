/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:24:58 by dgargant          #+#    #+#             */
/*   Updated: 2024/04/26 12:33:27 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		++len;
		s = s + 1;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;
	char	*p;

	i = 0;
	str = (char *)s1;
	if (!str)
		return (NULL);
	p = malloc(ft_strlen(str) + 1);
	if (p == 0)
		return (0);
	while (str[i] != '\0')
	{
		p[i] = str[i];
		++i;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*first;
	char	*second;
	char	*res;
	size_t	i;

	first = (char *)s1;
	second = (char *)s2;
	i = 0;
	if (first == NULL)
		return (second);
	else if (second == NULL)
		return (first);
	res = (char *) malloc((ft_strlen(first) + ft_strlen(second) + 1)
			* sizeof(char));
	if (res == NULL)
		return (NULL);
	while (*first != 0)
		res[i++] = *first++;
	while (*second != 0)
		res[i++] = *second++;
	res[i] = '\0';
	return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*p;

	i = 0;
	str = (char *)s;
	if (!str || start > ft_strlen(str))
	{
		p = (char *) malloc(1 * sizeof(char));
		if (p == NULL)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	if (len > (ft_strlen(str) - start))
		len = ft_strlen(str) - start;
	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (0);
	str += start;
	while (*str && (i < len))
		p[i++] = *str++;
	p[i] = '\0';
	return (p);
}
