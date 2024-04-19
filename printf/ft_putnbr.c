/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:21:13 by dgargant          #+#    #+#             */
/*   Updated: 2024/03/13 08:43:31 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	res;
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		result += write(1, "-2147483648", 11);
		return (result);
	}
	else if (n < 0)
	{
		result += write(1, "-", 1);
		n = n * (-1);
	}
	res = n % 10;
	if (n > 9)
		result += ft_putnbr(n / 10);
	res += 48;
	result += write(1, &res, 1);
	return (result);
}
