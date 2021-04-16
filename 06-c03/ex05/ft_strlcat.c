/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:04:08 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/10 17:20:33 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(const char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len)
		return (size + src_len);
	while (i < (size - dest_len - 1) && *(src + i) != '\0')
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
	*(dest + dest_len + i) = '\0';
	return (dest_len + src_len);
}

int				ft_strlen(const char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		len++;
		i++;
	}
	return (len);
}
