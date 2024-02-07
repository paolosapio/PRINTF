/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentualizeitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:53:38 by psapio            #+#    #+#             */
/*   Updated: 2024/02/07 21:48:15 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	percentualizeitor(char const *format, va_list args, int *count_char)
{
	int	n;

	n = 2;
	if (format[1] == 's')
		*count_char += print_string(va_arg(args, char *));
	else if ((format[1] == 'd') || (format[1] == 'i'))
		*count_char += ft_putnbr_pf(va_arg(args, int));
	else if (format[1] == 'c')
		*count_char += ft_putchar_pf(va_arg(args, int));
	else if (format[1] == 'x')
		*count_char += ft_int_to_exa(va_arg(args, unsigned int), 0);
	else if (format[1] == 'X')
		*count_char += ft_int_to_exa(va_arg(args, unsigned int), 1);
	else if (format[1] == 'p')
		*count_char += impressor_p(va_arg(args, void *));
	else if (format[1] == 'u')
		*count_char += ft_u(va_arg(args, unsigned int));
	else if (format[1] == '%')
		*count_char += write(1, "%", 1);
	else
		n = 1;
	return (n);
}
