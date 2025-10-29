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
// [fail]: your memmove does not support the overlap (test 2)
// [crash]: your memmove does not well with NULL as both parameters and size
// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	size_t				i;
// 	if (!dest || !src)
// 		return (NULL);
// 	i = 0;
// 	if ((unsigned char *)dest < (const unsigned char *)src + n)
// 	{
// 		while (n != 0)
// 		{
// 			*((unsigned char *)dest + n - 1)
// 				= *((const unsigned char *)src + n - 1);
// 			n--;
// 		}
// 	}
// 	else
// 	{
// 		while (i < n)
// 		{
// 			*(unsigned char *)dest++ = *(const unsigned char *)src++;
// 			i++;
// 		}
// 	}
// 	return (dest);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*destt;

	destt = (char *)dest;
	if (!dest || !src)
		return (NULL);
	i = 0;
	if ((unsigned char *)dest < (const unsigned char *)src + n)
	{
		while (n != 0)
		{
			*((unsigned char *)dest + n - 1)
				= *((const unsigned char *)src + n - 1);
			n--;
		}
		return (dest);
	}
	while (i < n)
	{
		*(unsigned char *)dest++ = *(const unsigned char *)src++;
		i++;
	}
	return (destt);
}
