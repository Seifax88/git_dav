/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:50:49 by dgargant          #+#    #+#             */
/*   Updated: 2024/03/14 11:39:22 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadecimal_lowercase(unsigned int n)
{
	char	*base;
	int		result;

	result = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		result += ft_puthexadecimal_lowercase(n / 16);
		result += ft_puthexadecimal_lowercase(n % 16);
	}
	else
		result += ft_putchar(base[n % 16]);
	return (result);
}

int	ft_puthexadecimal_uppercase(unsigned int n)
{
	char	*base;
	int		result;

	result = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		result += ft_puthexadecimal_uppercase(n / 16);
		result += ft_puthexadecimal_uppercase(n % 16);
	}
	else
		result += ft_putchar(base[n % 16]);
	return (result);
}
