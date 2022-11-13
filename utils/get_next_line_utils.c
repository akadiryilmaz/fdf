/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:32:56 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:32:57 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		ls;
	char	*dup;

	i = 0;
	ls = ft_strlen1(s);
	ls++;
	dup = malloc(ls);
	if (!dup)
		return (NULL);
	while (ls > 0)
	{
		dup[i] = s[i];
		i++;
		ls--;
	}
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)s + ft_strlen1(s));
	while (s[i] != 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	length;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen1(s);
	if (start >= length || !s)
		len = 0;
	else if (length < (start + len))
		len = length - start;
	dest = malloc(len + 1);
	if (dest != NULL)
	{
		while (i < len && s[i])
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen1(s1) + ft_strlen1(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s1[++i] != 0)
		dest[i] = s1[i];
	while (s2[j] != 0)
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	dest[i + j] = 0;
	return (dest);
}
