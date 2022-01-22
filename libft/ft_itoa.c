/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocky  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:01:30 by jrocky            #+#    #+#             */
/*   Updated: 2021/11/12 17:33:30 by jrocky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	int		nb;
	size_t	len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb / 10)
	{
		nb = nb / 10;
		len++;
	}
	return (++len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	len;

	len = ft_len(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	nb = n;
	if (len == 0)
		res[0] = 48;
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb)
	{
		res[len--] = 48 + (nb % 10);
		nb /= 10;
	}
	return (res);
}
