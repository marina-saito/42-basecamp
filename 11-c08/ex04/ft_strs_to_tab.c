/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:31:33 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/17 00:14:31 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1)
	{
		if (*(src + i) == '\0')
		{
			break ;
		}
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (src_len);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;

	if (ac <= 0 || av == NULL)
		return (NULL);
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (ac > 0)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = malloc(sizeof(char) * (tab[i].size + 1));
		ft_strlcpy(tab[i].copy, av[i], (unsigned int)(tab[i].size + 1));
		i++;
		ac--;
	}
	tab[i].size = 0;
	tab[i].str = 0;
	tab[i].copy = malloc(sizeof(char) * 1);
	tab[i].copy = 0;
	return (tab);
}
