/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:04:44 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/04 14:10:26 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1)
	{
		if (*(src + i) == '\0')
		{
			break ;
		}
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (src_len);
}

int				ft_strlen(char *str)
{
	int		len;
	char	*c;

	len = 0;
	c = str;
	while (*c != '\0')
	{
		len++;
		c++;
	}
	return (len);
}
