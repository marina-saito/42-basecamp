/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:11:04 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 11:09:26 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c);
int		check_if_valid_base(char *base);
int		ft_strlen(char *str);
int		find_pos_within_string(char *str, char c);

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int minus_sign;
	int res;

	i = 0;
	minus_sign = 0;
	res = 0;
	if (check_if_valid_base(base) == 0)
		return (0);
	while (ft_isspace(*(str + i)))
		i++;
	while (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			minus_sign++;
		i++;
	}
	while (find_pos_within_string(base, *(str + i)) >= 0)
	{
		res = res * ft_strlen(base) + find_pos_within_string(base, *(str + i));
		i++;
	}
	if (minus_sign % 2 == 1)
		res *= -1;
	return (res);
}

int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
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
		if (*(base + i) == '+' || *(base + i) == '-' || ft_isspace(*(base + i)))
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

int		find_pos_within_string(char *str, char c)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
			return (i);
		i++;
	}
	return (-1);
}
