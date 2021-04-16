/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:30:27 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/07 10:59:59 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(char *tab, int size);
void	print_hexa_addr(void *addr);
void	print_hexa_from_char(char c);
void	putstr_non_printable(char *str, int size);

/*
**		Only works with ASCII *char and if size < length of *char
*/

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				count;
	unsigned int	index;

	count = 0;
	index = 0;
	while (index < size)
	{
		print_hexa_addr(&*(addr + index));
		write(1, ": ", 2);
		while (count < 16)
		{
			if (index < size)
				print_hexa_from_char(*(char *)(addr + index));
			else
				write(1, "  ", 2);
			if (count % 2 == 1)
				write(1, " ", 1);
			count++;
			index++;
		}
		putstr_non_printable((char *)(addr + index - 16), 16);
		write(1, "\n", 1);
		count = 0;
	}
	return (addr);
}

void	ft_rev_int_tab(char *tab, int size)
{
	char	*left;
	char	*right;
	char	temp;
	int		i;

	left = tab;
	right = tab + size - 1;
	i = 0;
	while (i < size / 2)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		i++;
		left++;
		right--;
	}
}

void	print_hexa_addr(void *addr)
{
	unsigned long	lu_hexa_addr;
	char			char_hexa_addr[16];
	unsigned long	div;
	int				mod;
	int				i;

	lu_hexa_addr = (unsigned long)addr;
	i = 0;
	div = lu_hexa_addr / 16;
	mod = lu_hexa_addr % 16;
	while (i < 15)
	{
		char_hexa_addr[i] = '0' + mod + (mod <= 9 ? 0 : 39);
		mod = div % 16;
		div /= 16;
		i++;
	}
	ft_rev_int_tab(char_hexa_addr, 15);
	i = 0;
	while (*(char_hexa_addr + i) != '\0')
	{
		write(1, (char_hexa_addr + i), 1);
		i++;
	}
}

void	print_hexa_from_char(char c)
{
	int		mod;
	char	hex;

	hex = '0' + c / 16;
	write(1, &hex, 1);
	mod = c % 16;
	if (mod <= 9)
	{
		hex = '0' + mod;
	}
	else
	{
		hex = '0' + 39 + mod;
	}
	write(1, &hex, 1);
}

void	putstr_non_printable(char *str, int size)
{
	int		index;

	index = 0;
	while (index < size)
	{
		if (*(str + index) >= 32 && *(str + index) <= 126)
		{
			write(1, &*(str + index), 1);
		}
		else if (*(str + index) == '\0')
		{
			return ;
		}
		else
		{
			write(1, ".", 1);
		}
		index++;
	}
}
