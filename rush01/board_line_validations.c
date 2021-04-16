/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_line_validations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:52:07 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 00:26:12 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_functions.h"

int		rep_line(int board[4][4], int line)
{
	int col;
	int j;

	col = 0;
	while (col < 4)
	{
		j = 0;
		while (j < col)
		{
			if (board[line][col] == board[line][j] && board[line][col] != -1)
				return (0);
			j++;
		}
		col++;
	}
	return (1);
}

int		line_ctr_l2r(int board[4][4], int *ctr)
{
	int	views_l2r;
	int	curr_highest_l2r;
	int i;
	int line;

	line = 0;
	while (line < 4)
	{
		i = 0;
		views_l2r = 0;
		curr_highest_l2r = 0;
		while (i < 4)
		{
			if (board[line][i] > curr_highest_l2r)
			{
				views_l2r++;
				curr_highest_l2r = board[line][i];
			}
			i++;
		}
		if (ctr[line + 8] != views_l2r)
			return (0);
		line++;
	}
	return (1);
}

int		line_ctr_r2l(int board[4][4], int *ctr)
{
	int	views_r2l;
	int	curr_highest_r2l;
	int i;
	int line;

	line = 0;
	while (line < 4)
	{
		i = 0;
		views_r2l = 0;
		curr_highest_r2l = 0;
		while (i < 4)
		{
			if (board[line][3 - i] > curr_highest_r2l)
			{
				views_r2l++;
				curr_highest_r2l = board[line][3 - i];
			}
			i++;
		}
		if (ctr[line + 12] != views_r2l)
			return (0);
		line++;
	}
	return (1);
}
