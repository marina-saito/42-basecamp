/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:09:56 by renferre          #+#    #+#             */
/*   Updated: 2021/04/04 23:04:07 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	printline(int width, char mid);

void	rush(int x, int y)
{
	int line;

	printline(x, 'n');
	line = 1;
	while (line < y - 1)
	{
		printline(x, 'y');
		line++;
	}
	if (y >= 2)
	{
		printline(x, 'n');
	}
}

void	printline(int width, char mid)
{
	int		col;
	char	wall1;
	char	wall2;
	char	fill;

	wall1 = mid == 'y' ? 'B' : 'A';
	wall2 = mid == 'y' ? 'B' : 'C';
	fill = mid == 'y' ? ' ' : 'B';
	ft_putchar(wall1);
	col = 1;
	while (col < width - 1)
	{
		ft_putchar(fill);
		col++;
	}
	if (width >= 2)
	{
		ft_putchar(wall2);
	}
	ft_putchar('\n');
}
