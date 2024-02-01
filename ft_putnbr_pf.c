/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:37:38 by psapio            #+#    #+#             */
/*   Updated: 2024/02/01 14:41:03 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr_pf(int n)

{
	int		write_count;
	char	char_conv_mod;

	write_count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		char_conv_mod = -(n % 10) + '0';
		write_count++;
	}
	if (n < -9)
		write_count = write_count + ft_putnbr_pf(-(n / 10));
	if (n == 0)
	{
		write (1, "0", 1);
		write_count++;
		return (1);
	}
	if (n > 0)
		char_conv_mod = n % 10 + '0';
	if (n > 9)
		write_count = write_count + ft_putnbr_pf(n / 10);
	write_count = write_count +  write(1, &char_conv_mod, 1);
	return(write_count);
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
