/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:24:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/28 10:59:39 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	while (i < len_src)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}


char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*first_n;
	char		*aux;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (read (fd, buffer, BUFFER_SIZE))
	{
		aux = ft_strjoin(rest, buffer);
		if (rest)
			free(rest);
		rest = aux;
		free(aux);
		first_n = ft_strchr(aux, 10);
		while (!first_n)
		{
			rest = ft_strjoin("",buffer);
			free(buffer);
			buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			ft_bzero(buffer, BUFFER_SIZE + 1);
			read (fd, buffer, BUFFER_SIZE);
			aux = ft_strjoin(rest, buffer);
			first_n = ft_strchr(aux, 10);
		}
		aux = ft_substr(buffer, 0, first_n - buffer + 1);
		rest = ft_substr(buffer, first_n - buffer + 1, BUFFER_SIZE);
		line = malloc(sizeof(char) * ft_strlen(aux));
		free (line);
		line = ft_strcpy(line, aux);
		//free(aux);
		return (line);
	}
	else
		return (0);
}

void leakss()
{
	system ("leaks a.out");
}

int	main()
{
	int fd;

	atexit(leakss);

	fd = open("lotr.txt", O_RDONLY);
//	while (get_next_line(fd))
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));

	return 0;
}


