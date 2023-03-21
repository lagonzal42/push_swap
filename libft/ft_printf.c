/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:05:36 by lagonzal          #+#    #+#             */
/*   Updated: 2022/12/22 14:09:01 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "libft.h"

static const char	*g_hex = "0123456789abcdef";
static const char	*g_hexup = "0123456789ABCDEF";
static const char	*g_dec = "0123456789";

int	ft_select(char slctr, va_list arg_ptr)
{
	int	n;

	n = 0;
	if (slctr == 'c')
		n = ft_putchar_n(va_arg(arg_ptr, int));
	else if (slctr == 's')
		n = ft_putstr_n(va_arg(arg_ptr, char *));
	else if (slctr == 'p')
		ft_putnbr_n(va_arg(arg_ptr, unsigned long long), g_hex, &n);
	else if (slctr == 'd' || slctr == 'i')
		ft_putnbr_n(va_arg(arg_ptr, int), g_dec, &n);
	else if (slctr == 'u')
		ft_putnbr_n((unsigned) va_arg(arg_ptr, int), g_dec, &n);
	else if (slctr == 'x')
		ft_putnbr_n((unsigned) va_arg(arg_ptr, int), g_hex, &n);
	else if (slctr == 'X')
		ft_putnbr_n((unsigned) va_arg(arg_ptr, int), g_hexup, &n);
	else if (slctr == '%')
		n += write(1, "%", 1);
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_ptr;
	int		n;

	n = -1;
	va_start(arg_ptr, s);
	while (s[++n])
	{
		if (s[n] == '%')
		{
			n++;
			n += ft_select(s[n], arg_ptr) - 1;
		}
		else
			ft_putchar(s[n]);
	}
	va_end(arg_ptr);
	return (n);
}
