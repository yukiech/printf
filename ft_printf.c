/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:06:54 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/01 11:07:03 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_var(const char *to_print, va_list args, int i, int *count)
{
	char	*str;

	str = NULL;
	if (to_print[i + 1] == 's')
		ft_putstr_p((char *)va_arg(args, const char *), count);
	else if (to_print[i + 1] == 'c')
		ft_putchar_count((int)va_arg(args, int), count);
	else if (to_print[i + 1] == 'i' || to_print[i + 1] == 'd')
		ft_putnbr_p((int)va_arg(args, int), count);
	else if (to_print[i + 1] == '%')
		ft_putchar_count('%', count);
	else if (to_print[i + 1] == 'x')
		ft_putstr_p(ft_itoa_base_x(va_arg(args, int), 16, &str), count);
	else if (to_print[i + 1] == 'X')
		ft_putstr_p(ft_str_toup(ft_itoa_base_x(va_arg(args, int), 16, &str)),
			count);
	else if (to_print[i + 1] == 'u')
		ft_putnbr_long((unsigned int)va_arg(args, unsigned int), count);
	else if (to_print[i + 1] == 'p')
	{
		ft_putstr_p("0x", count);
		ft_putstr_p(ft_itoa_base_p((unsigned long int)va_arg(args, void *),
				16, &str), count);
	}
	free(str);
}

int	ft_printf(const char *to_print, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start (args, to_print);
	i = 0;
	count = 0;
	if (!to_print)
		return (0);
	while (to_print[i])
	{
		if (to_print[i] != '%')
			ft_putchar_count(to_print[i], &count);
		else
		{
			print_var(to_print, args, i, &count);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*int main()
{
	const char	*text;
	const char	*lettre;
	int			nombre;
	int			nombre2;
	unsigned int			nombre3;
	int			nombre4;
	int	printfc;
	void *ptr;

	text = "ft_tagueule";
	lettre = "c";
	nombre = 42424242;
	nombre2 = 43;
	nombre3 = 42;
	nombre4 = -1;
	printfc = 0;
	ptr = &nombre;

	printf("\n\n------------------------------\nx: \n");
	ft_printf("Result = %x\n", nombre);
	printf("Result = %x\n\n", nombre);

	printf("------------------------------\nX: \n");
	ft_printf("Result = %X\n", nombre);
	printf("Result = %X\n\n", nombre);

	printf("------------------------------\np: \n");
	ft_printf("Result = %p\n", ptr);
	printf("Result = %p\n\n", ptr);
	printf("------------------------------\n\n");

	//printf("N lettre: %d\n", count);
	//printf("Printf: %d\n", printfc);
	//	printf("Real: %x + %X", nombre3, nombre3);
}*/
