/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:46:39 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/29 18:28:31 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_putstr(const char *str)
{
	return ((int)write(1, str, ft_strlen(str)));
}

static int	ft_putnbr_base(long int nbr, char *base)
{
	int	bsize;
	int	len;

	bsize = (int)ft_strlen(base);
	len = 0;
	if (nbr < 0 && bsize == 10)
	{
		len += ft_putstr("-");
		nbr *= -1;
	}
	if (nbr / bsize != 0)
		len += ft_putnbr_base(nbr / bsize, base);
	len += (int)write(1, &base[nbr % bsize], 1);
	return (len);
}

static int	sort_format(const char *format, va_list ap)
{
	int	len;

	len = 0; 
	if (*format == 'c')
		len += write(1, &(char){(char)va_arg(ap, int)}, 1);
	if (*format == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (*format == 'i' || *format == 'd')
		len += ft_putnbr_base(va_arg(ap, int), "0123456789");
	if (*format == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_base(va_arg(ap, long int), "0123456789abcdef");
	}
	if (*format == 'u')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	if (*format == 'x')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	if (*format == 'X')
		len += ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	if (*format == '%')
		len += (int)write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (0);
			len += sort_format(format, ap);
			format++;
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (len);
}