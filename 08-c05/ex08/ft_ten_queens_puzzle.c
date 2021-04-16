/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:48:33 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/10 14:35:04 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	clear_board(int *board, int from_position);
void	fill_column(int *board, int col_to_fill, int *tot);
void	print_board(int *board);
int		check_if_line_is_acceptable(int *board, int line, int col_to_fill);

int		ft_ten_queens_puzzle(void)
{
	int	board[10];
	int tot;

	tot = 0;
	clear_board(board, 0);
	fill_column(board, 0, &tot);
	return (tot);
}

void	fill_column(int *board, int col_to_fill, int *tot)
{
	int line;

	if (col_to_fill == 10)
	{
		print_board(board);
		(*tot)++;
		return ;
	}
	line = 0;
	while (line < 10)
	{
		clear_board(board, col_to_fill);
		if (check_if_line_is_acceptable(board, line, col_to_fill) == 1)
		{
			board[col_to_fill] = line;
			fill_column(board, col_to_fill + 1, tot);
		}
		line++;
	}
}

void	print_board(int *board)
{
	int		j;
	char	c;

	j = 0;
	while (j < 10)
	{
		c = board[j] + 48;
		write(1, &c, 1);
		j++;
	}
	write(1, "\n", 1);
}

void	clear_board(int *board, int from_position)
{
	int j;

	j = from_position;
	while (j < 10)
	{
		board[j] = -1;
		j++;
	}
}

int		check_if_line_is_acceptable(int *board, int line, int col_to_fill)
{
	int col;

	col = 0;
	while (col < col_to_fill)
	{
		if (board[col] == line)
			break ;
		if (col_to_fill - col == line - board[col])
			break ;
		if (col_to_fill - col == board[col] - line)
			break ;
		col++;
	}
	if (col == col_to_fill)
		return (1);
	return (0);
}
