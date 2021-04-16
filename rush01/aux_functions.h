/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 00:15:23 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 00:31:00 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_FUNCTIONS_H
# define AUX_FUNCTIONS_H

int		rep_line(int board[4][4], int line);
int		rep_column(int board[4][4], int col);
int		line_ctr_l2r(int board[4][4], int *ctr);
int		line_ctr_r2l(int board[4][4], int *ctr);
int		col_ctr_t2b(int board[4][4], int *constraints);
int		col_ctr_b2t(int board[4][4], int *constraints);
int		check_if_valid_board(int board[4][4], int *ctr);
int		check_if_all_edges_have_1(int *constraints);
int		check_top_bottom_constraints(int *constraints);
int		check_left_right_constraints(int *constraints);
int		check_ctr(int *constraints);
void	print_board(int board[4][4]);
int		next_position(int board[4][4], int line, int col, int *constraints);
int		fill_board(int board[4][4], int line, int col, int *constraints);
void	fill_4s(int board[4][4], int *constraints);
void	fill_1234s(int board[4][4], int *constraints);
void	fill_pairs_12_23(int board[4][4], int *constraints);
void	complete_4s(int bd[4][4]);
void	fill_start(int board[4][4], int *constraints);
int		*string_to_int_array(char *argv_1);
int		valid_input(int *constraints);
int		validate_string(char *str);

#endif
