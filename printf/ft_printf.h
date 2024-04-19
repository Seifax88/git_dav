/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:21:40 by dgargant          #+#    #+#             */
/*   Updated: 2024/03/15 09:01:38 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);

int		ft_putchar(char c);

int		ft_putstr(char *str);

int		ft_putnbr(int n);

int		ft_putunbr(unsigned int n);

int		ft_puthexadecimal_lowercase(unsigned int n);

int		ft_puthexadecimal_uppercase(unsigned int n);

int		ft_putpadress(size_t n);

size_t	ft_strlen(const char *s);

#endif