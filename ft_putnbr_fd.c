/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloutman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:47:02 by hloutman          #+#    #+#             */
/*   Updated: 2025/10/20 23:47:03 by hloutman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	char	c;

	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);
}
// void	ft_putnbr_fd(int n, int fd)
// {
// 	int		i;
// 	char	*num;

// 	num = ft_itoa(n);
// 	i = 0;
// 	while (num[i])
// 	{
// 		write(fd, &num[i], 1);
// 		i++;
// 	}
// }
