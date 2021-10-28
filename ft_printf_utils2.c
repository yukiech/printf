/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:48:44 by ahuber            #+#    #+#             */
/*   Updated: 2021/10/28 10:11:42 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void	ft_putnbr_long(long int n, int *count)
{
	char	c;

	if (n < 0)
	{
		n = LONG_MAX - n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	c = n % 10 + '0';
	ft_putchar_count(c, count);
}

char	*ft_str_toupper(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] -= 32;
		i++;
	}
	return (c);
}
