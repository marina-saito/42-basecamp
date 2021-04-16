/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:37:09 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 18:07:00 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*rng;
	int	i;

	if (min >= max)
		return (NULL);
	rng = malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < (max - min))
	{
		rng[i] = min + i;
		i++;
	}
	return (rng);
}
