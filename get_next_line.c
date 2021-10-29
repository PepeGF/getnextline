/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:56:53 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/29 14:05:11 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_text(char *rest, int fd);
static char	*ft_plit_line(char *rest, int first_n);

char	*get_next_line(int fd)
{
	int			first_n;
	static char	*rest;

	printf("Soy rest al inicio de cada ejecución: %s\n",rest);
	first_n = ft_strchr(rest, 10);
	printf("Posicion del salto: ->%i\n",first_n);
	while(!first_n)
	{
		rest /*quiza aux*/ = ft_read_text(rest, fd);
	printf("Soy rest despues de cada lectura: %s\n",rest);
		if(!rest)
			return (0);
		first_n = ft_strchr(rest, 10);
	}

	return (ft_plit_line(rest, first_n));
}

static char	*ft_read_text(char *rest, int fd)
{
	char	*buffer;
	//char	*aux;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if(read(fd, buffer, BUFFER_SIZE))
	{
		/*aux quiza*/ rest = ft_strjoin(rest, buffer);
		//printf("Soy aux-> %s\n",aux);
		free(buffer);
		//rest = ft_substr(aux, 0, ft_strlen(aux));
		//free(aux);
		//free(rest);
		return(rest);
	}
	free(buffer);
	return (0);
}

static char	*ft_plit_line(char *rest, int first_n)
{
	size_t	len_rest;
	char	*line;
	char	*aux;

	len_rest = ft_strlen(rest);
	line = ft_substr(rest, 0, first_n + 1);;
	aux = ft_substr(rest, first_n + 1, len_rest);
	free(rest);
	rest = ft_substr(aux, 0, len_rest - first_n);
	//free(rest);
	free(line);
	return (line);
}

/*
static char	*ft_first_read(char *rest, int fd);
static char	*ft_more_reading(char *rest, int fd);

char	*get_next_line(int fd)
{
	static char	*rest;
//	char		*aux;
//	char		*line;
	int			first_n;

	//primera lectura necesaria, strjoin no hace mmalloc si una de las dos strings no exite
	if (!rest)
		rest = ft_first_read(rest, fd);
	first_n = ft_strchr(rest, 10);
	while (!first_n)
	{
		rest = ft_more_reading(rest, fd);
		first_n = ft_strchr(rest, 10);
		free (rest);
	}
	
	printf(" -> %i\n",first_n);
	return (rest);
}

static char	*ft_more_reading(char *rest, int fd)
{
	char	*buffer;
	char	*aux;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE))
	{
		printf("Direccion rest->%p\n",rest);
		printf("Direccion buffer->%p\n",buffer);
		free(rest);
		aux = ft_strjoin(rest, buffer);
		rest = ft_substr(aux, 0, ft_strlen(aux));
//		free(aux);
//		free(rest);
		printf("Soy otros rest->%s\n",rest);
		free(buffer);
		return (rest);
	}
	free(buffer);
	return (rest);
}


	printf("Soy el primer salto->%i\n", first_n);
	printf("----------------------------------\n");
	printf("Soy la primera lectura-> %s\n",rest);
	printf("----------------------------------\n");

	static char	*ft_first_read(char *rest, int fd)
{
	char	*buffer;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE))
	{
		//rest = ft_substr(buffer, 0, BUFFER_SIZE + 1);
		rest = ft_strjoin(rest, buffer);
		free(buffer);
		free(rest);
		printf("Soy el primer rest->%s\n",rest);
		printf("Direccion rest->%p\n",rest);
		printf("Direccion buffer->%p\n",buffer);
		return (rest);
	}
	free (buffer);
	return (0);
}
*/

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
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
//		printf("%s",get_next_line(fd));
//		printf("%s",get_next_line(fd));

	return 0;
}
