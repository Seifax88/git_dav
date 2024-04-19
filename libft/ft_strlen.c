/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:51:38 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/19 12:24:42 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		++len;
		s = s + 1;
	}
	return (len);
}

/*int	main(void)
{
	char str[50] = "hola, mundo";
	size_t lon = ft_strlen(str);

	printf("\nla string es: %s\n", str);

    printf("su longitud es: %lu\n", lon);
}*/