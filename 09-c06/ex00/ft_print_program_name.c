/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:44:12 by msayuri-          #+#    #+#             */
/*   Updated: 2021/04/10 16:23:49 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

int		main(int argc, char **argv)
{
	(void)argc;
	ft_putstr(argv[0]);
	write(1, "\n", 1);
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
