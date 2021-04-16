/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:32:18 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/12 09:27:58 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	sort_strings(char **strs, int nb);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);

int		main(int argc, char **argv)
{
	int		i;

	sort_strings(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_putstr(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}

void	sort_strings(char **strs, int nb)
{
	int		i;
	int		j;
	int		curr_min_idx;
	char	*aux;

	i = 0;
	while (i < nb)
	{
		j = i;
		curr_min_idx = j;
		while (j < nb)
		{
			if (ft_strcmp(strs[j], strs[curr_min_idx]) < 0)
				curr_min_idx = j;
			j++;
		}
		if (curr_min_idx != i)
		{
			aux = strs[i];
			strs[i] = strs[curr_min_idx];
			strs[curr_min_idx] = aux;
		}
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int diff;

	i = 0;
	while (*(s1 + i) != '\0')
	{
		diff = *(s1 + i) - *(s2 + i);
		if (diff != 0)
			return (diff);
		i++;
	}
	if (*(s2 + i) != '\0')
		return (*(s1 + i) - *(s2 + i));
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = *(src + i);
	return (dest);
}
