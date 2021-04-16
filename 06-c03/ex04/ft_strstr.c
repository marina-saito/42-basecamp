/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:40:09 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/07 14:00:06 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(const char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		to_find_len;
	int		str_len;

	i = 0;
	to_find_len = ft_strlen(to_find);
	str_len = ft_strlen(str);
	if (to_find_len == 0)
		return (str);
	while (i < (str_len + to_find_len))
	{
		if (*(str + i) == *to_find)
		{
			if (ft_strncmp(str + i, to_find, to_find_len) == 0)
				return (str + i);
		}
		i++;
	}
	return (0);
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

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	while (i < n && *(s1 + i) != '\0')
	{
		diff = *(s1 + i) - *(s2 + i);
		if (diff != 0)
			return (diff);
		i++;
	}
	if (i < n && *(s2 + i) != '\0')
		return (*(s1 + i) - *(s2 + i));
	return (0);
}
