/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:38:16 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/19 14:45:21 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_fill_array(char *str, int number, int len)
{
	while (number != 0)
	{
		str[len--] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				sign;
	int				len;
	unsigned int	number;

	sign = 1;
	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *) malloc (sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_fill_array(str, number, len);
	return (str);
}

/* 
#include <stdio.h>
int main() {
	int num = 12345;
	char* str = ft_itoa(num);
	printf("The string representation of %d is %s\n", num, str);

	num = -2147483648;
	str = ft_itoa(num);
	printf("The string representation of %d is %s\n", num, str);

	num = 0;
	str = ft_itoa(num);
	printf("The string representation of %d is %s\n", num, str);

	free(str);

	return 0;
} */