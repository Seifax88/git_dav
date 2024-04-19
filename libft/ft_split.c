/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:54:57 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/22 11:25:13 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_empty_array(char **array, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	ft_count_words(char *buffer, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
			i++;
		else
		{
			words++;
			while (buffer[i] != c && buffer[i] != '\0')
				i++;
		}
	}
	return (words);
}

static void	ft_fill_array(char *array, char *buffer, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		array[i] = buffer[start];
		start++;
		i++;
	}
	array[i] = '\0';
}

static char	**split(char *str, char **array, char c, int end)
{
	size_t	i;
	size_t	start;

	i = 0;
	array = malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (str[end] != '\0')
	{
		if (str[end] == c)
			end++;
		else
		{
			start = end;
			while (str[end] != c && str[end] != '\0')
				end++;
			array[i] = malloc((end - start + 1) * sizeof(char));
			if (array[i] == NULL)
				return (ft_empty_array(array, i));
			ft_fill_array(array[i], str, start, end);
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**array;
	size_t	end;

	end = 0;
	str = (char *)s;
	array = NULL;
	return (split(str, array, c, end));
}

/*#include <stdio.h>
int main()
{
	char const *s = "^^^1^^2a,^^^^3^^^^--h^^^^";
    char c = '^';
    char **result = ft_split(s, c);

    // Imprimir el resultado
    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
    }

    // Liberar la memoria
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}*/
