/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:32:04 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:32:06 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    const char s[] = " asdfghj";
    printf("%lu \n", ft_strlen(s));
    printf("%lu \n", strlen(s));
    return 0;
}
*/
