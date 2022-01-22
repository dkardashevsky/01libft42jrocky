/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocky  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:01:39 by jrocky            #+#    #+#             */
/*   Updated: 2021/11/12 17:55:51 by jrocky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	wordc;

	wordc = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			wordc++;
			while (*s != c && *s)
				s++;
		}
	}
	return (wordc);
}

static void	ft_splitclear(char **split)
{
	char	**iter;

	iter = split;
	while (*iter)
	{
		free(iter);
		iter++;
	}
	free(split);
}

static void	ft_splitwords(char **split, char const *s, char c, size_t wordc)
{
	unsigned int	wstart;
	size_t			wlen;
	char			**iter;

	wstart = 0;
	wlen = 0;
	iter = split;
	while (wordc--)
	{
		while (s[wstart] == c && s[wstart])
			wstart++;
		while (s[wstart + wlen] != c && s[wstart + wlen])
			wlen++;
		*iter = ft_substr(s, wstart, wlen);
		if (*iter == NULL)
		{
			ft_splitclear(split);
			return ;
		}
		wstart += wlen;
		wlen = 0;
		iter++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	wordc;

	if (s == NULL)
		return (NULL);
	wordc = ft_countwords(s, c);
	split = (char **) malloc((wordc + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split[wordc] = NULL;
	ft_splitwords(split, s, c, wordc);
	return (split);
}
