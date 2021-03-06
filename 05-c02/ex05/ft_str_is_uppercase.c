/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:50:04 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/03 22:52:39 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		if (!(*c >= 'A' && *c <= 'Z'))
		{
			return (0);
		}
		c++;
	}
	return (1);
}
