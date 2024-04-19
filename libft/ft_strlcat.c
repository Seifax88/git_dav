/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:39:55 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/21 11:05:00 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen((char *)src);
	if (dlen >= dstsize || dstsize == 0)
		return (dstsize + slen);
	while (src[i] != '\0' && i < (dstsize - dlen - 1))
	{
		dst[dlen + i] = src[i];
		++i;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
