/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:36:50 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/08 11:48:50 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(char c);

int	ft_atoi(char *str)
{
	int i;
	int minus_sign;
	int res;

	i = 0;
	minus_sign = 0;
	res = 0;
	while (ft_isspace(*(str + i)))
		i++;
	while (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			minus_sign++;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	if (minus_sign % 2 == 1)
		res *= -1;
	return (res);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\f' ||
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}
