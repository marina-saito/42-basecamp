/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:16 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 00:25:38 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_functions.h"

int		check_if_valid_board(int board[4][4], int *ctr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (rep_line(board, i) == 0 || rep_column(board, i) == 0)
			return (0);
		i++;
	}
	if (line_ctr_l2r(board, ctr) == 0 || line_ctr_r2l(board, ctr) == 0)
		return (0);
	if (col_ctr_t2b(board, ctr) == 0 || col_ctr_b2t(board, ctr) == 0)
		return (0);
	return (1);
}
