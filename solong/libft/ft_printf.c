/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:21:07 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/27 12:06:52 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_letter(va_list args, char letter)
{
	int	result;

	result = 0;
	if (letter == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (letter == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (letter == 'd' || letter == 'i')
		result += ft_putnbr(va_arg(args, int));
	else if (letter == 'u')
		result += ft_putunbr(va_arg(args, unsigned int));
	else if (letter == 'x')
		result += ft_puthexadecimal_lowercase(va_arg(args, unsigned int));
	else if (letter == 'X')
		result += ft_puthexadecimal_uppercase(va_arg(args, unsigned int));
	else if (letter == 'p')
	{
		result += write(1, "0x", 2);
		if (result < 0)
			return (result);
		result += ft_putpadress(va_arg(args, size_t));
	}
	else if (letter == '%')
		return (ft_putchar('%'));
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		result;
	int		i;

	result = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				result += check_letter(args, str[++i]);
		}
		else
			result += ft_putchar(str[i]);
		if (result < 0)
			return (result);
		i++;
	}
	va_end(args);
	return (result);
}
