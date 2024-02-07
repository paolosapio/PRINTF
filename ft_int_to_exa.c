/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_exa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:53:10 by psapio            #+#    #+#             */
/*   Updated: 2024/02/07 20:34:47 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_to_exa(unsigned int n, int mi_ma)
{
	int			write_count;
	char		char_conv_mod;
	const char	*dic_mi = "0123456789abcdef";
	const char	*dic_ma = "0123456789ABCDEF";

	write_count = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		write_count++;
		return (1);
	}
	if (mi_ma == 0)
		char_conv_mod = dic_mi[n % 16];
	else
		char_conv_mod = dic_ma[n % 16];
	if (n > 15)
		write_count = write_count + ft_int_to_exa(n / 16, mi_ma);
	write_count = write_count + write(1, &char_conv_mod, 1);
	return (write_count);
}
/*
#include <fcntl.h>
int main(void)
{
int numero;
int file_descriptor;

file_descriptor = open("libro_pizza", O_RDWR);
numero = 10;
ft_putnbr_pf(numero,file_descriptor);
}*/
