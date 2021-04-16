/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:59:01 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/07 12:20:09 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(const char *str);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (i < nb && *(src + i) != '\0')
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
	*(dest + dest_len + i) = '\0';
	return (dest);
}

int		ft_strlen(const char *str)
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
