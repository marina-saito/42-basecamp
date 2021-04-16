/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_col_validations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:54:50 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 00:26:07 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_functions.h"

int		rep_column(int board[4][4], int col)
{
	int line;
	int i;

	line = 0;
	while (line < 4)
	{
		i = 0;
		while (i < line)
		{
			if (board[line][col] == board[i][col] && board[line][col] != -1)
				return (0);
			i++;
		}
		line++;
	}
	return (1);
}

int		col_ctr_t2b(int board[4][4], int *constraints)
{
	int	views_t2b;
	int	curr_highest_t2b;
	int i;
	int col;

	col = 0;
	while (col < 4)
	{
		i = 0;
		views_t2b = 0;
		curr_highest_t2b = 0;
		while (i < 4)
		{
			if (board[i][col] > curr_highest_t2b)
			{
				views_t2b++;
				curr_highest_t2b = board[i][col];
			}
			i++;
		}
		if (constraints[col] != views_t2b)
			return (0);
		col++;
	}
	return (1);
}

int		col_ctr_b2t(int board[4][4], int *constraints)
{
	int	views_b2t;
	int	curr_highest_b2t;
	int i;
	int col;

	col = 0;
	while (col < 4)
	{
		i = 0;
		views_b2t = 0;
		curr_highest_b2t = 0;
		while (i < 4)
		{
			if (board[3 - i][col] > curr_highest_b2t)
			{
				views_b2t++;
				curr_highest_b2t = board[3 - i][col];
			}
			i++;
		}
		if (constraints[col + 4] != views_b2t)
			return (0);
		col++;
	}
	return (1);
}
