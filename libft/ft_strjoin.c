/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocky  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:02:19 by jrocky            #+#    #+#             */
/*   Updated: 2021/11/12 17:47:10 by jrocky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*res;

	i = 0;
	j = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	res = malloc(sizeof(char) * (i + j) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
		res[x++] = s1[i++];
	j = 0;
	while (s2[j])
		res[x++] = s2[j++];
	res[x] = '\0';
	return (res);
}
