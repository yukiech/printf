/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:14:35 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/01 11:01:31 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_p(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*count = *count + 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar_count(s[i], count);
		i++;
	}
}

void	ft_putnbr_p(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count = *count + 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_count('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_p(n / 10, count);
	c = n % 10 + '0';
	ft_putchar_count(c, count);
}

static int	convert_base(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char	*ft_itoa_base_p(unsigned long int value, unsigned long int base,
			char **str)
{
	int					i;
	unsigned long int	tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	*str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	(*str)[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		(*str)[i] = convert_base(tmp);
		value /= base;
		i--;
	}
	return (*str);
}

char	*ft_itoa_base_x(unsigned int value, unsigned int base, char **str)
{
	int					i;
	unsigned long int	tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	*str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	(*str)[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		(*str)[i] = convert_base(tmp);
		value /= base;
		i--;
	}
	return (*str);
}
