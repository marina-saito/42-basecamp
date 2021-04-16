/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:06:23 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 12:16:32 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Babylonian square-root algorithm
*/

int		count_digits(int nb);
int		first_guess(int number_of_digits);

int		ft_sqrt(int nb)
{
	int digits;
	int	curr_guess;
	int	prev_guess;
	int	next_guess;

	if (nb <= 0 || (nb % 2 == 0 && nb % 4 != 0))
		return (0);
	if (nb % 10 == 2 || nb % 10 == 3 || nb % 10 == 7 || nb % 10 == 8)
		return (0);
	digits = count_digits(nb);
	curr_guess = first_guess(digits);
	prev_guess = -1;
	next_guess = -1;
	while (curr_guess != prev_guess)
	{
		next_guess = (curr_guess + nb / curr_guess) / 2;
		if (next_guess == prev_guess)
			return (0);
		prev_guess = curr_guess;
		curr_guess = next_guess;
		if (curr_guess * curr_guess == nb)
			return (curr_guess);
	}
	return (0);
}

int		count_digits(int nb)
{
	int	digits;

	digits = 0;
	while (nb > 0)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}

int		first_guess(int number_of_digits)
{
	int i;
	int guess;

	i = 1;
	guess = 1;
	while (i < number_of_digits / 2)
	{
		guess *= 10;
		i++;
	}
	return (guess);
}
