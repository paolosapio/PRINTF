/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:16:23 by psapio            #+#    #+#             */
/*   Updated: 2024/02/01 14:41:41 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


char    *ft_strchr(const char *s, int c);

int print_string(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	percentualizeitor(char const *format, va_list arguments, int *count_char)
{
	int n;

	n = 2;
	if (format[1] == 's')
		*count_char += print_string(va_arg(arguments, char*));
	else if ((format[1] == 'd') || (format[1] == 'i'))
		*count_char += ft_putnbr_pf(va_arg(arguments, int));
/*
	else if (format[1] == 'c')
		//funcion que imprime char;
	else if (format[1] == 'x')
		//funcion que imprime exadecimales;
	else if (format[1] == 'X')
		//funcion que imprime exadecimales mayuscculos;
	else if (format[1] == 'p')
		//funcion que imprime direcion de memoria en exadecimal;
	else if (format[1] == '%')
		//imprime simplemente un '%'*/
	else
		n = 1;
	return (n);
}

int ft_printf(char const *format, ...)
{
	va_list	arguments;
	int		i;
	int		count_char;

	i = 0;
	count_char = 0;
	va_start(arguments, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = i + percentualizeitor(format + i, arguments, &count_char);
		else
		{
			count_char = count_char +  write(1, &format[i], 1);
			i++;
		}
	}
	va_end(arguments);
	return (count_char);
}

int main (void)
{
    char name[] = "Paolo";
    int edad = -444;
	int n_print_return;

	n_print_return = ft_printf("Hola me llamo %s y tengo %d años\n", name, edad);
	printf("%d\n", n_print_return);
}
