/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:26:03 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 00:26:51 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "aux_functions.h"

int		fill_board(int board[4][4], int line, int col, int *constraints)
{
	int box;

	if (board[line][col] != -1)
	{
		if (next_position(board, line, col, constraints) == 1)
			return (1);
	}
	box = 1;
	while (box < 5)
	{
		board[line][col] = box;
		if (rep_line(board, line) == 0 || rep_column(board, col) == 0)
		{
			board[line][col] = -1;
			box++;
			continue ;
		}
		if (next_position(board, line, col, constraints) == 1)
			return (1);
		board[line][col] = -1;
		box++;
	}
	return (0);
}

int		next_position(int board[4][4], int line, int col, int *constraints)
{
	if (line < 4 && col < 3)
		return (fill_board(board, line, col + 1, constraints));
	if (line < 3 && col == 3)
		return (fill_board(board, line + 1, 0, constraints));
	if (line == 3 && col == 3)
	{
		if (check_if_valid_board(board, constraints) == 1)
		{
			print_board(board);
			return (1);
		}
	}
	return (0);
}

void	print_board(int board[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = board[i][j] + 48;
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
