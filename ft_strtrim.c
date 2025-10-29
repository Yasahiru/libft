/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloutman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:01:16 by hloutman          #+#    #+#             */
/*   Updated: 2025/10/20 23:21:05 by hloutman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_start(const char *str, const char *set)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (str[i])
	{
		j = 0;
		check = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				check = 1;
			j++;
		}
		if (!check)
			break ;
		i++;
	}
	return ((char *)&str[i]);
}

static char	*ft_end(const char *str, const char *set)
{
	int	i;
	int	j;
	int	check;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		j = 0;
		check = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				check = 1;
			j++;
		}
		if (!check)
			break ;
		i--;
	}
	return ((char *)&str[++i]);
}

static int	ft_len(const char *start, const char *end)
{
	int	i;

	i = 0;
	while (&start[i] != end)
		i++;
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*start;
	char	*end;
	char	*str;
	int		len;
	int		i;

	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	len = ft_len(start, end);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = start[i];
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}
/*
#include <stdio.h>
int main(){
	const char*str = "+-+_hamza+laoutmani_+_*-";
	const char*set = "+*-";
	//char*start = ft_start(str,set);
	//char*end = ft_end(str,set);
	//int res = ft_len(start,end);
	char*res = ft_strtrim(str,set);
	printf("%s",res);
}*/
