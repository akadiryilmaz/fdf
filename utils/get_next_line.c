/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:32:21 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:32:22 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim(char *str)
{
	char	*dest;

	dest = ft_strchr(str, '\n');
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*dest;
	int			size;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = '\0';
	while (size > 0)
	{
		if (!str)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	free(buffer);
	dest = ft_substr(str, 0, ft_strchr(str, '\n') - str + 1);
	str = ft_trim(str);
	return (dest);
}
