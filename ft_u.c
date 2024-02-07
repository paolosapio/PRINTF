/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:05:32 by psapio            #+#    #+#             */
/*   Updated: 2024/02/07 21:30:53 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n)
{
	int		write_count;
	char	char_conv_mod;

	write_count = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	char_conv_mod = n % 10 + '0';
	if (n > 9)
		write_count = write_count + ft_putnbr_pf(n / 10);
	write_count += write(1, &char_conv_mod, 1);
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
