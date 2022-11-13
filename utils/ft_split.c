/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayilmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:31:12 by ayilmaz           #+#    #+#             */
/*   Updated: 2022/11/12 20:31:14 by ayilmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h" 

static int	ft_strmylen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] == c)
			return (i + 1);
	}
	return (i + 1);
}

static int	ft_totalstrlen(const char *str, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != '\0' && str[i + 1] != c)
			k++;
		i++;
	}
	return (k + 2);
}

static void	createlist(int k, char **list, char *s, char c)
{
	int	j;
	int	i;

	i = 0;
	while (i < ft_totalstrlen(s, c) - 1 && s[k])
	{
		while (s[k] == c && s[k])
			k++;
		list[i] = (char *)malloc(sizeof(char) * ft_strmylen(&s[k], c));
		j = 0;
		while (s[k] != c && s[k])
		{
			list[i][j] = s[k];
			j++;
			k++;
		}
		if (j == 0)
			list[i] = 0;
		else
			list[i][j] = '\0';
		i++;
	}
	list[i] = 0;
}

char	**ft_split(const char *s, char c)
{
	int		k;
	char	**list;

	if (!s)
		return (NULL);
	list = (char **) malloc(sizeof (char *) * ft_totalstrlen(s, c));
	if (!list)
		return (0);
	k = 0;
	while (s[k] == c && s[k])
		k++;
	createlist(k, list, (char *)s, c);
	return (list);
}
/*
#include <stdio.h>
int    main()
{
    int    i;
    i = 0;
    
    char list[] = "mmammimmammimmammimmammimmammammimmammimmammi";
    char **ali = ft_split(list, 'i');
    
    while(ali[i])
    {
        printf("%d : %s\n", i, ali[i]);
        i++;
    }
    return 0;
}*/
