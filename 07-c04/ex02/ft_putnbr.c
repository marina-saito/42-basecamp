/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:32:59 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 21:31:53 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
