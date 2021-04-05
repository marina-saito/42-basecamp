/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:52:03 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/01 23:49:24 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void increment_nbr(char *nbr, int size);
void initialize_char_array(char *nbr, int size, int first_digit);
void print_char_array(char *nbr, int size);
int compare_char_arrays(char *arr1, char *arr2, int size);

/*
** nbr		:	char array representing the combination of n numbers in
**				ascending order
** max_comb	:	char array representing the maximum possible combination
**				of n numbers in ascending order
*/

void	ft_print_combn(int n)
{
	char	nbr[n];
	char	max_comb[n];
	int		i;

	initialize_char_array(nbr, n, 0);
	initialize_char_array(max_comb, n, 10 - n);
	i = 0;
	while (!compare_char_arrays(nbr, max_comb, n))
	{
		print_char_array(nbr, n);
		write(1, ",", 1);
		write(1, " ", 1);
		increment_nbr(nbr, n);
		i++;
	}
	print_char_array(nbr, n);
}

void	increment_nbr(char *nbr, int size)
{
	int i;

	i = size - 1;
	if (nbr[size - 1] == '9')
	{
		while (nbr[i - 1] == nbr[i] - 1)
		{
			i--;
		}
		(nbr[i - 1])++;
		while (i < size)
		{
			nbr[i] = nbr[i - 1] + 1;
			i++;
		}
	}
	else
	{
		(nbr[i])++;
	}
}

void	initialize_char_array(char *nbr, int size, int first_digit)
{
	int i;

	nbr[0] = '0' + first_digit;
	i = 1;
	while (i < size)
	{
		nbr[i] = nbr[i - 1] + 1;
		i++;
	}
}

void	print_char_array(char *nbr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, &nbr[i], 1);
		i++;
	}
}

int		compare_char_arrays(char *arr1, char *arr2, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr1[i] != arr2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
