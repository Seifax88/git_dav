/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:32:51 by dgargant          #+#    #+#             */
/*   Updated: 2024/03/15 09:00:25 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	result;

	result = 0;
	if (!str)
	{
		result += write(1, "(null)", 6);
		return (result);
	}
	return (write(1, str, ft_strlen(str)));
}
