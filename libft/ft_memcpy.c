/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocky  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:02:03 by jrocky            #+#    #+#             */
/*   Updated: 2021/11/12 17:36:00 by jrocky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)destination;
	s = (char *)source;
	if (!source && !destination)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (destination);
}
