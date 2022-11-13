/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:30:16 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:30:18 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long int n)
{
	int	length;

	length = 0;
	if (n >= 16)
		length += ft_printpointer(n / 16);
	length += ft_putchar("0123456789abcdef"[n % 16]);
	return (length);
}

int	base(char *baset, int nbr, int n, char c)
{
	int	length;

	length = 0;
	if (nbr < 0)
	{
		if (c != 'x' && c != 'X' && c != 'u')
		{
			length += ft_putchar('-');
			if (nbr <= -n)
				length += base(baset, (nbr / n) * -1, n, c);
			length += ft_putchar((baset[-1 * (nbr % n)]));
		}
		else
		{
			if ((unsigned int)nbr >= (unsigned int)n)
				length += base(baset, ((unsigned int)nbr / n), n, c);
			length += ft_putchar((baset[((unsigned int)nbr % n)]));
		}
	}
	if (nbr >= n)
		length += base(baset, nbr / n, n, c);
	if (nbr >= 0)
		length += ft_putchar(baset[nbr % n]);
	return (length);
}
