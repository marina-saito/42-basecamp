/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:42:51 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 21:55:13 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_if_valid_base(char *base);
int		ft_strlen(char *str);
void	ft_rev_char_tab(char *tab, int size);
void	ft_putstr(char *str);

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_copy;
	int		base_size;
	char	res[33];
	int		i;

	if (check_if_valid_base(base) == 0)
		return ;
	nbr_copy = nbr;
	base_size = ft_strlen(base);
	if (nbr_copy < 0)
	{
		write(1, "-", 1);
		nbr_copy *= -1;
	}
	i = 0;
	while (nbr_copy > 0 || i == 0)
	{
		res[i] = base[nbr_copy % base_size];
		nbr_copy /= base_size;
		i++;
	}
	res[i] = '\0';
	ft_rev_char_tab(res, ft_strlen(res));
	ft_putstr(res);
}

int		check_if_valid_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	base_len = ft_strlen(base);
	if (base_len == 0 || base_len == 1)
		return (0);
	i = 0;
	while (i < base_len)
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (*(base + j) == *(base + i))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_rev_char_tab(char *tab, int size)
{
	char i;
	char temp;

	i = 0;
	while (i < size / 2)
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = temp;
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(1, (str + i), 1);
		i++;
	}
}
