/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:16:23 by psapio            #+#    #+#             */
/*   Updated: 2024/02/07 21:58:40 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(char const *format, ...)
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
			i += percentualizeitor(format + i, arguments, &count_char);
		else
		{
			count_char += write(1, &format[i], 1);
			if (count_char == -1)
				return (-1);
			i++;
		}
	}
	va_end(arguments);
	return (count_char);
}
/*
int main (void)
{
    char name[] = "Paolo";
    int edad = 44;
	char letter = 'S';
	int n_print_return;

	   n_print_return = printf("original: %p\n", name);
	ft_printf("cuenta mia de caracteres impresos:%d\n", n_print_return);
	n_print_return = ft_printf("mia: %p\n", name);
	printf("cuenta original de caracteres impresoso: %d\n", n_print_return);

}*/
