/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:16:23 by psapio            #+#    #+#             */
/*   Updated: 2024/01/26 19:01:01 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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

int	percentualizeitor(char const *format, va_list arguments, int *count_arg)
{
	char *dict = "sdicxXp";
	int i;
	
	i = 0 ;
	{
		if (!ft_strchr(dict, format[1]))
			return (1);
		else if (format[1] == 's')
			*count_arg = *count_arg + print_string(va_arg(arguments, char*));


	return (2);
	}
}

int ft_printf(char const *format, ...)
{
	va_list	arguments;
	int			i;
	int			count_arg;

	i = 0;
	count_arg = 0;
	va_start(arguments, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = i + percentualizeitor(format + i, arguments, &count_arg);
		else
		{
			count_arg = count_arg +  write(1, &format[i], 1);
			i++;
		}
	}
	va_end(arguments);
	return (count_arg);
}

int main (void)
{
    char name[] = "Paolo";
    int edad = 44;

    ft_printf("Hola me llamo %s\n", name, edad);
}
