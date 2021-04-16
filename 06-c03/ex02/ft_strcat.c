/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:34:31 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/07 11:45:15 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(const char *str);

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (*(src + i) != '\0')
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
