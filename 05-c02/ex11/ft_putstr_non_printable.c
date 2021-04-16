/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:55:03 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/08 09:45:23 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		char_is_printable(char c);
void	print_hexa_from_char(char c);

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (char_is_printable(*(str + i)))
		{
			write(1, &*(str + i), 1);
		}
		else
		{
			write(1, "\\", 1);
			print_hexa_from_char(*(str + i));
		}
		i++;
	}
}

int		char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	print_hexa_from_char(char c)
{
	char	*hexa;
	char	hexa_non_printable[2];

	hexa = "0123456789abcdef";
	hexa_non_printable[0] = hexa[(unsigned char)c / 16];
	hexa_non_printable[1] = hexa[(unsigned char)c % 16];
	write(1, hexa_non_printable, 2);
}
