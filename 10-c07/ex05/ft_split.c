/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 08:32:44 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/16 18:49:22 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char *src, unsigned int n);
int		ft_strlen(char *str);
int		find_pos_in_str(char *str, char c);

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int		str_len;
	int		curr_len;
	int		i;
	int		j;

	str_len = ft_strlen(str);
	splitted = malloc(sizeof(char*) * str_len);
	i = 0;
	j = 0;
	while (i < str_len)
	{
		curr_len = 0;
		while (find_pos_in_str(charset, *(str + i)) >= 0 && i < str_len)
			i++;
		while (find_pos_in_str(charset, *(str + i)) < 0 && i < str_len)
		{
			curr_len++;
			i++;
		}
		splitted[j] = ft_substr((str + i - curr_len), curr_len);
		j++;
	}
	splitted[j] = 0;
	return (splitted);
}

char	*ft_substr(char *src, unsigned int n)
{
	unsigned int	i_dest;
	unsigned int	i_src;
	char			*dest;

	if (n == 0)
		return (0);
	dest = malloc(sizeof(char) * (n + 1));
	i_dest = 0;
	i_src = 0;
	while (i_dest < n)
	{
		dest[i_dest] = src[i_src];
		if (*(src + i_src) != '\0')
			i_src++;
		i_dest++;
	}
	dest[i_dest] = '\0';
	return (dest);
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

int		find_pos_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
			return (i);
		i++;
	}
	return (-1);
}
