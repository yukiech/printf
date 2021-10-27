/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:12:35 by ahuber            #+#    #+#             */
/*   Updated: 2021/10/27 17:30:19 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

extern int	g_count;

int		ft_printf(const char *to_print, ...);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putnbr_long(long int n);
char	*ft_itoa_base(unsigned long int value, unsigned long int base);
char	*ft_itoa_base_x(unsigned int value, unsigned int base);
char	*ft_str_toupper(char *c);
void	ft_putchar_count(char c);

#endif
