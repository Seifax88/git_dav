/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:47:58 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/22 11:30:30 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*cdest;
	const char	*csrc;

	cdest = (char *)dst;
	csrc = (const char *)src;
	if (cdest < csrc)
	{
		i = 0;
		while (i < len)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else if (cdest > csrc)
	{
		i = len;
		while (i != 0)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (cdest);
}
