/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:57:50 by psapio            #+#    #+#             */
/*   Updated: 2024/02/07 20:29:49 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	impressor_p(void *n)
{
	unsigned long	n2;
	int				write_count;

	n2 = (unsigned long)n;
	write_count = write(1, "0x", 2);
	return (ft_if_pointer(n2) + write_count);
}

int	ft_if_pointer(unsigned long n)
{
	int			write_count;
	char		char_conv_mod;
	const char	*dic_mi = "0123456789abcdef";

	write_count = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		write_count++;
		return (1);
	}
	char_conv_mod = dic_mi[n % 16];
	if (n > 15)
		write_count = write_count + ft_if_pointer(n / 16);
	write_count = write_count + write(1, &char_conv_mod, 1);
	return (write_count);
}
