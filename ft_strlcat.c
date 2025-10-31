/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloutman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:59:59 by hloutman          #+#    #+#             */
/*   Updated: 2025/10/18 23:09:11 by hloutman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destl;
	size_t	srcl;
	size_t	i;

	if (!dest || !src)
		return (0);
	srcl = ft_strlen(src);
	destl = ft_strlen(dest);
	i = 0;
	if (size <= destl)
		return (size + srcl);
	if (size > destl)
	{
		while (i < size - destl - 1 && src[i])
		{
			dest[destl + i] = src[i];
			i++;
		}
		dest[destl + i] = '\0';
	}
	return (destl + srcl);
}
