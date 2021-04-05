/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:09:43 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/02 23:23:26 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int copy_a;
	int copy_b;

	copy_a = *a;
	copy_b = *b;
	*a = copy_a / copy_b;
	*b = copy_a % copy_b;
}
