/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:03:48 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/07 17:52:57 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		char_is_alpha(char c);
int		char_is_numeric(char c);
int		char_is_upcase(char c);
int		char_is_lowcase(char c);

char	*ft_strcapitalize(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		while (!(char_is_alpha(*c) || char_is_numeric(*c)) && *c != '\0')
		{
			c++;
		}
		if (char_is_lowcase(*c))
		{
			*c -= 32;
		}
		c++;
		while (char_is_alpha(*c) || char_is_numeric(*c))
		{
			if (char_is_upcase(*c))
			{
				*c += 32;
			}
			c++;
		}
	}
	return (str);
}

int		char_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		char_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		char_is_upcase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		char_is_lowcase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
