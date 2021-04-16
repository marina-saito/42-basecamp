/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:49:36 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/14 20:21:38 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*str_dup;
	int		i;

	src_len = ft_strlen(src);
	str_dup = malloc(sizeof(char) * (src_len + 1));
	i = 0;
	while (i < src_len)
	{
		str_dup[i] = *(src + i);
		i++;
	}
	return (str_dup);
}

int		ft_strlen(char *str)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		len++;
		i++;
	}
	return (len);
}
