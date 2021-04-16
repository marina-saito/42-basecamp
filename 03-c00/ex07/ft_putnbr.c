/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:12:34 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/16 20:41:33 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int power_base_10(int power);
int count_digits(int nb);

void	ft_putnbr(int nb)
{
	int		digits;
	int		copy_nb;
	int		i_digit;
	char	c_digit;

	copy_nb = nb;
	digits = count_digits(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (digits > 0)
	{
		i_digit = nb / power_base_10(digits - 1);
		c_digit = i_digit + 48;
		write(1, &c_digit, 1);
		nb -= i_digit * power_base_10(digits - 1);
		digits--;
	}
}

int		power_base_10(int power)
{
	int result;

	result = 1;
	while (power > 0)
	{
		result *= 10;
		power--;
	}
	return (result);
}

int		count_digits(int nb)
{
	int copy_nb;
	int digits;

	copy_nb = nb;
	digits = 0;
	if (nb == 0)
	{
		digits = 1;
	}
	while (copy_nb != 0)
	{
		copy_nb /= 10;
		digits++;
	}
	return (digits);
}
