/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:41:44 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/07 09:55:51 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
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
