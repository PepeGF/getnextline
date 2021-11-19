/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:46:54 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/19 20:22:06 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#define BUFFER_SIZE 1
//#define LINEAS 0

char    *ft_split_line(char **rest,int first_n);
char    *ft_readtext(int fd, int *first_n, char **rest);

char	*get_next_line(int fd)
{
	static char	*rest;
	int			first_n;

	first_n = ft_strchr(rest, 10);
	if (first_n == -1)
		ft_readtext(fd, &first_n, &rest);
	return (ft_split_line(&rest, first_n));


}

char    *ft_readtext(int fd, int *first_n, char **rest)
{
	char	*buffer;
	char	*aux;
	int		lenread;

	buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero (buffer, BUFFER_SIZE + 1);
	lenread = read (fd, buffer, BUFFER_SIZE + 1);
	aux = ft_strjoin(*rest, buffer);
	free (buffer);
	*rest = ft_strdup (aux);
	free (aux);
	*first_n = ft_strchr (*rest, 10);
	return (*rest);
}

char    *ft_split_line(char **rest,int first_n)
{
	char	*line;
	char	*aux;

	line = ft_substr(*rest, 0, first_n + 1);
	aux = ft_substr(*rest, first_n + 1, ft_strlen(*rest) - first_n - 1);
	free (*rest);
	*rest = aux;
	return (line);
}

int main()
{
	int		fd;
	char	*line;
	fd = open("textito.txt", O_RDONLY);
	line = ft_strdup(get_next_line(fd));
	printf("%s",line);
	free (line);
	line = ft_strdup(get_next_line(fd));
	printf("%s",line);
	free (line);
	line = ft_strdup(get_next_line(fd));
	printf("%s",line);
	free (line);
	return (0);
}

