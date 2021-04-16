/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:05:31 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/08 14:57:10 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}
