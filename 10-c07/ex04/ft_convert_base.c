/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:21:28 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/14 00:26:03 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_if_valid_base(char *base);
int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);
int		ft_itoa_base(char *str, int nbr, char *base, int base_size);
long	ft_abs(long nbr);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_atoi_base;
	char	*res;
	int		base_size;

	if (check_if_valid_base(base_from) == 0)
		return (NULL);
	if (check_if_valid_base(base_to) == 0)
		return (NULL);
	nbr_atoi_base = ft_atoi_base(nbr, base_from);
	res = malloc(sizeof(char) * 33);
	base_size = ft_strlen(base_to);
	ft_itoa_base(res, nbr_atoi_base, base_to, base_size);
	return (res);
}

int		ft_itoa_base(char *str, int nbr, char *base, int base_size)
{
	int		digit;

	digit = -1;
	if (ft_abs(nbr) >= base_size || digit == 0)
	{
		digit = ft_itoa_base(str, nbr / base_size, base, base_size);
		str[digit + 1] = '\0';
	}
	if (nbr >= 0)
	{
		if (nbr < base_size)
			digit = 0;
		str[digit] = base[nbr % base_size];
	}
	if (nbr < 0)
	{
		if (nbr > -base_size)
		{
			str[0] = '-';
			digit = 1;
		}
		str[digit] = base[-(nbr % base_size)];
	}
	return (digit + 1);
}

long	ft_abs(long nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}
