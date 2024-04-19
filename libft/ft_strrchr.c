/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:27:06 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/20 09:46:39 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	char		letter;

	p = 0;
	letter = (char)c;
	if (letter == '\0')
		return ((char *)(s + ft_strlen((char *)s)));
	if (s == 0)
		return (0);
	while (*s)
	{
		if (*s == letter)
			p = s;
		s++;
	}
	return ((char *)p);
}
