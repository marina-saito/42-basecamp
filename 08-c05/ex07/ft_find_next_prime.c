/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:48:35 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/13 19:39:59 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb);

int		ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (2);
	if (nb == 2 || nb == 3)
		return (nb);
	if (ft_is_prime(nb))
		return (nb);
	i = nb / 6;
	while (1)
	{
		if (ft_is_prime(6 * i - 1) && 6 * i - 1 >= nb)
			return (6 * i - 1);
		if (ft_is_prime(6 * i + 1) && 6 * i + 1 >= nb)
			return (6 * i + 1);
		i++;
	}
	return (0);
}

int		ft_is_prime(int nb)
{
	int	i;

	if (nb <= 0 || nb == 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb && i <= 46340)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}
