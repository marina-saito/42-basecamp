/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:36:47 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 00:27:18 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_functions.h"

void	fill_start(int board[4][4], int *constraints)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = -1;
			j++;
		}
		i++;
	}
	fill_4s(board, constraints);
	fill_1234s(board, constraints);
	fill_pairs_12_23(board, constraints);
	complete_4s(board);
}

void	fill_4s(int board[4][4], int *constraints)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (constraints[i] == 1)
		{
			if (i <= 3)
				board[0][i] = 4;
			if (i >= 4 && i <= 7)
				board[3][i - 4] = 4;
			if (i >= 8 && i <= 11)
				board[i - 8][0] = 4;
			if (i >= 12)
				board[i - 12][3] = 4;
		}
		i++;
	}
}

void	fill_1234s(int board[4][4], int *constraints)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (constraints[i] == 4)
		{
			if (i <= 7)
			{
				board[0 + 3 * (i / 4)][i - 4 * (i / 4)] = 1;
				board[1 + 1 * (i / 4)][i - 4 * (i / 4)] = 2;
				board[2 - 1 * (i / 4)][i - 4 * (i / 4)] = 3;
				board[3 - 3 * (i / 4)][i - 4 * (i / 4)] = 4;
			}
			else if (i >= 8 && i <= 15)
			{
				board[i - 8 - 4 * (i / 12)][0 + 3 * (i / 12)] = 1;
				board[i - 8 - 4 * (i / 12)][1 + 1 * (i / 12)] = 2;
				board[i - 8 - 4 * (i / 12)][2 - 1 * (i / 12)] = 3;
				board[i - 8 - 4 * (i / 12)][3 - 3 * (i / 12)] = 4;
			}
		}
		i++;
	}
}

void	fill_pairs_12_23(int board[4][4], int *constraints)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i <= 3 && constraints[i] == 1 && constraints[i + 4] == 2)
			board[3][i] = 3;
		if (i <= 3 && constraints[i] == 2 && constraints[i + 4] == 1)
			board[0][i] = 3;
		if (i >= 8 && i <= 11 && constraints[i] == 1 && constraints[i + 4] == 2)
			board[i - 8][3] = 3;
		if (i >= 8 && i <= 11 && constraints[i] == 2 && constraints[i + 4] == 1)
			board[i - 8][0] = 3;
		if (i <= 3 && constraints[i] == 2 && constraints[i + 4] == 3)
			board[1][i] = 4;
		if (i <= 3 && constraints[i] == 3 && constraints[i + 4] == 2)
			board[2][i] = 4;
		if (i >= 8 && i <= 11 && constraints[i] == 2 && constraints[i + 4] == 3)
			board[i - 8][1] = 4;
		if (i >= 8 && i <= 11 && constraints[i] == 3 && constraints[i + 4] == 2)
			board[i - 8][2] = 4;
		i++;
	}
}

void	complete_4s(int bd[4][4])
{
	int	i;
	int	line_without_4;
	int	missing_4s;
	int	col_without_4;

	line_without_4 = 0;
	missing_4s = 0;
	col_without_4 = 0;
	i = -1;
	while (++i < 4)
	{
		if (bd[i][0] != 4 && bd[i][1] != 4 && bd[i][2] != 4 && bd[i][3] != 4)
		{
			line_without_4 = i;
			missing_4s++;
		}
		if (bd[0][i] != 4 && bd[1][i] != 4 && bd[2][i] != 4 && bd[3][i] != 4)
		{
			col_without_4 = i;
			missing_4s++;
		}
	}
	if (missing_4s == 2)
		bd[line_without_4][col_without_4] = 4;
}
