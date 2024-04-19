/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:37 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/23 09:27:35 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	l;
	char	*str;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == 0)
		return (str);
	i = 0;
	while (i < l)
	{
		str[i] = (*f)(i, s[i]);
		++i;
	}
	str[i] = 0;
	return (str);
}

/*int main() {
    // Define a string
    char *s = "hello";

    // Call ft_strmapi with the string and the to_uppercase function
    char *result = ft_strmapi(s, to_uppercase);

    // Print the result
    printf("%s\n", result);

    // Free the allocated memory
    free(result);

    return 0;
}*/