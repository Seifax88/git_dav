/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:09:53 by dgargant          #+#    #+#             */
/*   Updated: 2024/06/07 11:14:54 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H


# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

size_t	strlen_no_tab(const char *s);

//get_next_line functions
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_substr(const char *s, unsigned int start, size_t len);

int	ft_strncmp(char *s1, char *s2, size_t n);

char	*ft_itoa(int n);

#endif