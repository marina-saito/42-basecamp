/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:49:47 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/02 23:58:51 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int *left;
	int *right;
	int i;
	int temp;

	left = tab;
	right = tab + size - 1;
	i = 0;
	while (i < size / 2)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		i++;
		left++;
		right--;
	}
}
