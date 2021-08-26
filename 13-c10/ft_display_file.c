/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msayuri- <msayuri-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:09:16 by msayuri-          #+#    #+#             */
/*   Updated: 2021/05/14 16:40:42 by msayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_display_file(int argc, char **argv)
{
	int		fd;
	char	buf[1];
	ssize_t	bytesRead;

	if (argc == 0)
	{
		ft_putstr("File name missing.\n");
		return ;
	}
	if (argc > 1)
	{
		ft_putstr("Too many arguments.\n");
		return ;
	}
	fd = open(argv[0], O_RDONLY);
	bytesRead = read(fd, buf, 1);
	if (bytesRead == -1)
		ft_putstr("Cannot read file.");
	while (bytesRead == 1)
	{
		write(1, buf, 1);
		bytesRead = read(fd, buf, 1);
	}
	write(1, "\n", 1);
	close(fd);
}
