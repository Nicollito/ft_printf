/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:46:39 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/28 12:05:56 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
static int	ft_putnbr_base()
{

}

static int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

static int	sort_format(const char *format, va_list ap)
{
	int	len;

	if (*format == 'c')
		len = ft_putstr(va_arg(ap, char *));
	if (*format == 's')
		len = ft_putstr(va_arg(ap, char *));
	if (*format == 'p')
	if (*format == 'd')
	if (*format == 'i' || *format == 'u')
	if (*format == 'x')
	if (*format == 'X')
	if (*format == '%')
	if (len == -1)
		return (-1);
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
			temp = sort_format(*format++, ap);
			if (temp == -1);
				return (0);
			len += temp;
		}
		temp = ft_putstr(*format);
		if (temp == -1);
			return (-1);
		len += temp;
		*format++;
	}
}
