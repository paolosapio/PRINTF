/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42madrid.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:35:09 by psapio            #+#    #+#             */
/*   Updated: 2024/02/02 18:14:44 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(char const *format, ...);
int		percentualizeitor(char const *format, va_list arguments, int *count_char);
int		ft_putnbr_pf(int n);
char	*ft_strchr(const char *s, int c);
int		print_string(char *str);
int		ft_putchar_pf(char c);
#endif
