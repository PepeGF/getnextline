/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/22 23:41:40 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split_line(char **rest, int first_n);
char	*ft_readtext(int fd, int *first_n, char **rest, size_t *lenrest);

char	*get_next_line(int fd)
{
	static char	*rest;
	int			first_n;
	size_t		lenrest;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
		return (0);
	lenrest = ft_strlen(rest);
	lenrest *= 1;
	first_n = ft_strchr(rest, 10);
	if (!ft_readtext(fd, &first_n, &rest, &lenrest))
	{
		if (rest)
			free(rest);
		return (0);
	}
	else
		return (ft_split_line(&rest, first_n));
}

char	*ft_readtext(int fd, int *first_n, char **rest, size_t *lenrest)
{
	char	*buffer;
	char	*aux;
	int		lenread;

	while (*first_n == -1)
	{
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		ft_bzero (buffer, BUFFER_SIZE + 1);
		lenread = read (fd, buffer, BUFFER_SIZE);
		if (lenread == -1 || (lenread == 0 && *lenrest == 0))
		{
			free (buffer);
			return (0);
		}
		*lenrest += lenread;
		//printf("%lu\n",*lenrest);
		aux = ft_strjoin(*rest, buffer);
		free(buffer);
		if (*rest)
			free(*rest);
		*rest = ft_strdup(aux);
		free(aux);
		//cambiar este first_n
		*first_n = ft_strchr(*rest, 10);
		//seguir modificando *first_n desde aquí
		if ((*first_n == -1 && lenread < BUFFER_SIZE) || lenread == 0)
			*first_n = ft_strlen(*rest);
	}
	return (*rest);
}

char	*ft_split_line(char **rest, int first_n)
{
	char	*line;
	char	*aux;

	line = ft_substr(*rest, 0, first_n + 1);
	aux = ft_substr(*rest, first_n + 1, ft_strlen(*rest) - first_n - 1);
	free (*rest);
	*rest = aux;
	return (line);
}

int	main(void)
{
	int	fd;
	char	*line;
	fd = open(FILEPATH, O_RDONLY);
	line = get_next_line(fd);
	line[0] = '0';
	//printf("%s",line);
	free (line);
	line = get_next_line(fd);
	//printf("%s",line);
	free (line);
	//line = get_next_line(fd);
	//printf("%s",line);
	//free (line);
	close (fd);
	return (0);
}

