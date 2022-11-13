/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:35:55 by maltunda          #+#    #+#             */
/*   Updated: 2022/11/11 18:55:39 by maltunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);

char			**ft_split(char const *s, char c);

char			*ft_strdup1(const char *s1);

char			*ft_strjoin1(char const *s1, char const *s2);

size_t			ft_strlen(const char *s);

#endif
