/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wololo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:43:28 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/27 14:58:25 by josgarci         ###   ########.fr       */
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

//puede que haya q añadir BFFSIZE

static char	*ft_fill_buffer(char *buffer, int fd)
{
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_bzero(buffer, BUFFER_SIZE + 1);
	//puede que sea necesario hacer free (buffer) aquí, si todo funciona, no
	read (fd, buffer, BUFFER_SIZE);
	buffer = ft_strjoin(rest, buffer);
	return (buffer);
}

static char	*ft_read_again(char *rest, char *buffer, int fd)
{
	rest = ft_strchr(rest, buffer);
	buffer = ft_fill_buffer(buffer, fd);
}

static char	*ft_split_line(char *rest, char *buffer, char *aux, char *line)
{
	size_t	len_aux;

	len_aux = ft_strlen(aux);
	aux = ft_substr(buffer, 0, first_n - buffer + 1);
	rest = ft_substr(buffer, first_n - buffer + 1, BUFFER_SIZE);
	free (rest);
	line = malloc(sizeof(char) * (len_aux + 1));
	ft_bzero(line, len_aux + 1);
	line = ft_strcpy(line, aux);
	free (aux);
	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*aux;
	char		*line;
	int			first_n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_fill_buffer(buffer, fd);
	first_n = ft_strchr(buffer, 10);
	while (!first_n)
	{
		ft_read_again();
		first_n = ft_strchr(buffer, 10);
	}
	if (first_n)//	si hay salto en el buffer
	{
		line = ft_split_line();
	}
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("el_quijote.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
