/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:53:56 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/14 23:02:03 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src);
int		ft_strlen(const char *str);
int		ft_max_strlen(char **strs, int size);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;
	int		len_sep;
	int		max_len_strs;
	int		i;

	if (size <= 0 || sep == NULL)
		return (malloc(0));
	len_sep = ft_strlen(sep);
	max_len_strs = ft_max_strlen(strs, size);
	strjoin = malloc(size * (max_len_strs + len_sep) * sizeof(char));
	if (strjoin == NULL)
		return (malloc(0));
	ft_strcat(strjoin, *strs);
	i = 1;
	while (i < size)
	{
		ft_strcat(strjoin, sep);
		ft_strcat(strjoin, *(strs + i));
		i++;
	}
	return (strjoin);
}

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

int		ft_max_strlen(char **strs, int size)
{
	int	max_len;
	int	curr_len;
	int	i;

	max_len = 0;
	i = 0;
	while (i < size)
	{
		curr_len = ft_strlen(*(strs + i));
		if (curr_len > max_len)
			max_len = curr_len;
		i++;
	}
	return (max_len);
}
