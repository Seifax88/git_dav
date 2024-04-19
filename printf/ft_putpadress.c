/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpadress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:34:32 by dgargant          #+#    #+#             */
/*   Updated: 2024/03/13 08:43:42 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpadress(size_t n)
{
	char	*base;
	int		result;

	result = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		result += ft_putpadress(n / 16);
		result += ft_putpadress(n % 16);
	}
	else
		result += ft_putchar(base[n % 16]);
	return (result);
}
