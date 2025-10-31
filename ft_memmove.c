/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloutman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:35:40 by hloutman          #+#    #+#             */
/*   Updated: 2025/10/19 00:59:59 by hloutman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*destt;

	destt = (char *)dest;
	if (!dest || !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	i = 0;
	if ((dest > src))
	{
		while (n != 0)
		{
			*((char *)dest + n - 1) = *((char *)src + n - 1);
			n--;
		}
		return (destt);
	}
	while (dest && src && i < n)
	{
		*(unsigned char *)dest++ = *(const unsigned char *)src++;
		i++;
	}
	return (destt);
}
