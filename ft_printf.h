/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:12:35 by ahuber            #+#    #+#             */
/*   Updated: 2021/10/28 12:53:38 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *to_print, ...);
void	ft_putstr_printf(char *s, int *count);
void	ft_putnbr_printf(int n, int *count);
void	ft_putnbr_long(long int n, int *count);
char	*ft_itoa_base_printf(unsigned long int value, unsigned long int base);
char	*ft_itoa_base_x_printf(unsigned int value, unsigned int base);
char	*ft_str_toupper(char *c);
void	ft_putchar_count(char c, int *count);

#endif
