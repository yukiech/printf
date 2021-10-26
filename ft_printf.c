/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:06:54 by ahuber            #+#    #+#             */
/*   Updated: 2021/10/26 11:32:31 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_var(const char * to_print, va_list args, int i)
{
	if (to_print[i+1] == 's' /*|| to_print[i + 1] == 'c'*/)
		ft_putstr((char *)va_arg(args, const char *));
	else if (to_print[i+1] == 'c')
		ft_putchar_count((char)va_arg(args, const char *));
	else if (to_print[i+1] == 'i' || to_print[i+1] == 'd')
		ft_putnbr((int)va_arg(args, int));
	else if (to_print[i+1] == '%')
		ft_putchar_count('%');
	else if (to_print[i+1] == 'x')
		ft_putstr(ft_itoa_base(va_arg(args, int), 16));
	else if (to_print[i+1] == 'X')
		ft_putstr(ft_str_toupper(ft_itoa_base(va_arg(args, int), 16)));
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
			ft_putchar_count(to_print[i]);
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

/*int main()
{
	const char	*text;
	const char	*lettre;
	int			nombre;
	int			nombre2;
	unsigned int			nombre3;
	int	printfc;

	text = "ft_tagueule";
	lettre = "c";
	nombre = 42;
	nombre2 = 43;
	nombre3 = 42;
	printfc = 0;

	ft_printf("Result: %s + %c + %d + %i + %x + %X + %%\n", text, lettre, nombre, nombre2, nombre3, nombre3);
	printfc = printf("Result: %s + %s + %d + %i + %x + %X + %%\n", text, lettre, nombre, nombre2, nombre3, nombre3);
	printf("N lettre: %d\n", count);
	printf("N lettre: %d\n", printfc);
	//	printf("Real: %x + %X", nombre3, nombre3);
}*/
