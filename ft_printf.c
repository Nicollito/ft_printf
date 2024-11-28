/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:46:39 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/28 16:26:21 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int	ft_putstr(const char *str)
{
	return (write(1, str, ft_strlen(str)));
}

static int	ft_putnbr_base(int nbr, char *base)
{
	int	bsize;

	bsize = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putstr("-");
		nbr *= -1;
	}
	if (nbr / bsize != 0)
		ft_putnbr_base(nbr / bsize, base);
	return (ft_putstr((char *)(nbr % bsize + '0')));
}

static int	sort_format(const char *format, va_list ap)
{
	int	len;

	format++;
	if (*format == 'c')
		len = write(1, &(char){(char)va_arg(ap, int)}, 1);
	if (*format == 's')
		len = ft_putstr(va_arg(ap, char *));
	if (*format == 'i' || *format == 'd')
		ft_putnbr_base(va_arg(ap, int), "0123456789");
/* 	if (*format == 'p')
	if (*format == 'u')
	if (*format == 'x')
	if (*format == 'X')
	if (*format == '%') */
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		temp;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			temp = sort_format(format, ap);
			//printf("test");
			if (temp == -1)
				return (-1);
			len += temp;
			format++;
		}
		else
			temp = write(1, format, 1);
			if (temp == -1)
				return (-1);
			len += temp;
		format++;
	}
	return (len);
}
