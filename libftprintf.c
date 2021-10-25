/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:06:54 by ahuber            #+#    #+#             */
/*   Updated: 2021/10/25 17:16:19 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_var(const char * to_print, va_list args, int i)
{
	char *str; // temp

	if (to_print[i+1] == 's' /*|| to_print[i + 1] == 'c'*/)
		ft_putstr((char *)va_arg(args, const char *));
	else if (to_print[i+1] == 'c')
		ft_putstr((char *)va_arg(args, const char *));
	else if (to_print[i+1] == 'i' || to_print[i+1] == 'd')
		ft_putnbr((int)va_arg(args, int));
	else if (to_print[i+1] == '%')
		write(1, "%", 1);
	else if (to_print[i+1] == 'x')
		ft_putstr(ft_itoa_base(va_arg(args, int), 16));
	else if (to_print[i+1] == 'X')
		str = ft_itoa_base(va_arg(args, int), 16);
		printf("%s", str);
		str = ft_str_toupper(str);
		printf("%s", str);
		ft_putstr(str);
}

int	ft_printf(const char *to_print, ...)
{
	int	i;
	va_list args;

	va_start (args, to_print);
	i = 0;
	if(!to_print)
		return(0);
	while (to_print[i])
	{
		if (to_print[i] != '%')
			write(1, &to_print[i], 1);
		else
		{
			print_var(to_print, args, i);	
		i++;
		}
		i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	const char	*text;
	const char	*text2;
	const char	*lettre;
	int			nombre;
	int			nombre2;
	int			nombre3;

	text = "ft_tagueule";
	text2 = "PasGentil";
	lettre = "c";
	nombre = 42;
	nombre2 = 43;
	nombre3 = 42;

	ft_printf("Result: %s + %s + %c + %d + %i + %x + %X +  %%\n", text, text2, lettre, nombre, nombre2, nombre3, nombre3);
	printf("Real: x = %x | X = %X", nombre3, nombre3);
}
