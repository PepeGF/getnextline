/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:56:53 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/28 13:26:53 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*aux;
	char		*line;
	int			first_n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	read(fd, buffer, BUFFER_SIZE);
	rest = buffer;
	first_n = ft_strchr(rest, 10);
	if (first_n)
	{
		aux = ft_substr(rest, 0, first_n + 1);
		line = aux;
		free (aux);
		aux = ft_substr(rest, first_n + 1, BUFFER_SIZE - first_n);
		rest = aux;
		free (buffer);
		return (line);
	}
	free(buffer);
	return (rest);
}

void leakss()
{
	system ("leaks a.out");
}

int	main()
{
	int fd;

	atexit(leakss);

	fd = open("el_quijote.txt", O_RDONLY);
//	while (get_next_line(fd))
//		printf("%s",get_next_line(fd));
get_next_line(fd);

	return 0;
}
