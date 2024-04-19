/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:09:32 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/23 09:25:26 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*t;
	char	*s;

	i = 0;
	t = (char *) dst;
	s = (char *) src;
	if (!t && !s)
		return (0);
	while (i < n)
	{
		t[i] = s[i];
		i++;
	}
	return (t);
}
