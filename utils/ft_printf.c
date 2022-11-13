/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:30:33 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:30:35 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	a = a % 256;
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *a)
{
	int	length;

	length = 0;
	if (!a)
		return (ft_putstr("(null)"));
	while (*a != '\0')
		length += ft_putchar(*(a++));
	return (length);
}

int	ichecker(va_list argp, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_putchar((char)va_arg(argp, int));
	if (c == 's')
		length = ft_putstr(va_arg(argp, char *));
	if (c == 'p')
	{
		length = write(1, "0x", 2);
		length += ft_printpointer(va_arg(argp, unsigned long int));
	}
	if (c == 'd' || c == 'i')
		length = base("0123456789", va_arg(argp, int), 10, c);
	if (c == 'u')
		length = base("0123456789", va_arg(argp, unsigned int), 10, c);
	if (c == 'x')
		length = base("0123456789abcdef", va_arg(argp, unsigned int), 16, c);
	if (c == 'X')
		length = base("0123456789ABCDEF", va_arg(argp, unsigned int), 16, c);
	if (c == '%')
		length = ft_putchar(c);
	return (length);
}

int	ft_printf(const char *xd, ...)
{
	int		length;
	va_list	argp;

	length = 0;
	va_start(argp, xd);
	while (*xd != '\0')
	{
		if (*xd == '%')
			length += ichecker(argp, *(++xd));
		else
			length += ft_putchar(*xd);
		xd++;
	}
	va_end(argp);
	return (length);
}
