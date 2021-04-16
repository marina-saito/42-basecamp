/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:55:02 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/14 09:56:24 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*src_ptr;
	char			*dest_ptr;
	unsigned int	i;

	src_ptr = src;
	dest_ptr = dest;
	i = 0;
	while (i < n)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		if (*src_ptr != '\0')
		{
			src_ptr++;
		}
		i++;
	}
	return (dest);
}
