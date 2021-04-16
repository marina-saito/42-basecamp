/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:07:29 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/14 15:32:04 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				i;
	unsigned long	check_range_size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (range == NULL)
		return (-1);
	check_range_size = max - min;
	*range = malloc(sizeof(int) * (check_range_size));
	if (check_range_size > 2147483647 || *range == NULL)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
