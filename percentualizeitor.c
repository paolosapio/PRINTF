/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentualizeitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:53:38 by psapio            #+#    #+#             */
/*   Updated: 2024/02/02 18:17:15 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int percentualizeitor(char const *format, va_list arguments, int *count_char)
{
    int n;

    n = 2;
    if (format[1] == 's')
        *count_char += print_string(va_arg(arguments, char*));
    else if ((format[1] == 'd') || (format[1] == 'i'))
        *count_char += ft_putnbr_pf(va_arg(arguments, int));
	else if (format[1] == 'c')
        *count_char += ft_putchar_pf(va_arg(arguments, int));
/*    
	else if (format[1] == 'x')
			*count_char += ft_putnbr_pf(va_arg(arguments, int));
        //funcion que imprime exadecimales;
    else if (format[1] == 'X')
        *count_char += ft_putnbr_pf(va_arg(arguments, int));
        //funcion que imprime exadecimales mayuscculos;
    else if (format[1] == 'p')
        *count_char += ft_putnbr_pf(va_arg(arguments, int));
        //funcion que imprime direcion de memoria en exadecimal;
*/
    else if (format[1] == '%')
       *count_char +=  write(1, "%", 1);
    else
        n = 1;
    return (n);
}
