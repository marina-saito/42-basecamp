/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 23:55:35 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/17 00:10:24 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_putnbr(nb / 10);
	}
	if (nb >= 0)
	{
		ft_putchar(nb % 10 + '0');
	}
	if (nb < 0)
	{
		if (nb > -10)
			ft_putchar('-');
		ft_putchar(-(nb % 10) + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, par[i].size);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		write(1, par[i].copy, par[i].size);
		ft_putchar('\n');
		i++;
	}
}
