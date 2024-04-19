/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:23:26 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/16 12:39:43 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	target;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (*p == target)
			return (p);
		i++;
		p++;
	}
	return (0);
}
