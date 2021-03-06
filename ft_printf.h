/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:12:35 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/01 10:55:33 by ahuber           ###   ########.fr       */
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
void	ft_putstr_p(char *s, int *count);
void	ft_putnbr_p(int n, int *count);
void	ft_putnbr_long(long int n, int *count);
char	*ft_itoa_base_p(unsigned long int value, unsigned long int base,
			char **str);
char	*ft_itoa_base_x(unsigned int value, unsigned int base, char **str);
char	*ft_str_toup(char *c);
void	ft_putchar_count(char c, int *count);

#endif
