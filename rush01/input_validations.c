/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:04:07 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 00:25:44 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "aux_functions.h"

/*
** Check if every edge has a single 1 and if impossible pairs
** are found: 4 <-> 2; 4 <-> 3; 4 <-> 4; 1 <-> 1; 3 <-> 3
*/

int		check_ctr(int *constraints)
{
	if (check_if_all_edges_have_1(constraints) == 0)
		return (0);
	else if (check_top_bottom_constraints(constraints) == 0)
		return (0);
	else if (check_left_right_constraints(constraints) == 0)
		return (0);
	else
		return (1);
}

int		check_if_all_edges_have_1(int *constraints)
{
	int i;
	int	ones[4];

	i = -1;
	ones[0] = 0;
	ones[1] = 0;
	ones[2] = 0;
	ones[3] = 0;
	while (++i <= 15)
	{
		if (*(constraints + i) == 1)
		{
			if (i <= 3)
				ones[0] = ones[0] + 1;
			else if (i >= 4 && i <= 7)
				ones[1] = ones[1] + 1;
			else if (i >= 8 && i <= 11)
				ones[2] = ones[2] + 1;
			else if (i >= 12)
				ones[3] = ones[3] + 1;
		}
	}
	if (ones[0] == 1 && ones[1] == 1 && ones[2] == 1 && ones[3] == 1)
		return (1);
	return (0);
}

int		check_top_bottom_constraints(int *constraints)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		if (constraints[i] == 4 && constraints[i + 4] == 2)
			return (0);
		else if (constraints[i] == 2 && constraints[i + 4] == 4)
			return (0);
		else if (constraints[i] == 4 && constraints[i + 4] == 3)
			return (0);
		else if (constraints[i] == 3 && constraints[i + 4] == 4)
			return (0);
		else if (constraints[i] == 4 && constraints[i + 4] == 4)
			return (0);
		else if (constraints[i] == 1 && constraints[i + 4] == 1)
			return (0);
		else if (constraints[i] == 3 && constraints[i + 4] == 3)
			return (0);
		i++;
	}
	return (1);
}

int		check_left_right_constraints(int *constraints)
{
	int i;

	i = 8;
	while (i <= 11)
	{
		if (constraints[i] == 4 && constraints[i + 4] == 2)
			return (0);
		else if (constraints[i] == 2 && constraints[i + 4] == 4)
			return (0);
		else if (constraints[i] == 4 && constraints[i + 4] == 3)
			return (0);
		else if (constraints[i] == 3 && constraints[i + 4] == 4)
			return (0);
		else if (constraints[i] == 4 && constraints[i + 4] == 4)
			return (0);
		else if (constraints[i] == 1 && constraints[i + 4] == 1)
			return (0);
		else if (constraints[i] == 3 && constraints[i + 4] == 3)
			return (0);
		i++;
	}
	return (1);
}
