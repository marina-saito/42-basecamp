/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:51:42 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/04 09:52:09 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		if (*c >= 'A' && *c <= 'Z')
		{
			*c += 32;
		}
		c++;
	}
	return (str);
}
