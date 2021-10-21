/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:24:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/21 11:22:24 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		BUFFER_SIZE;	//solo vale para pruebas
	char		*buffer;
	char		*aux;
	static char	*rest;
	char		*first_n;
	char		*line;
//	static t_list	line;		idea posible hacerlo con listas

	BUFFER_SIZE = 5;		//solo vale para prubas

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	first_n = ft_strchr(buffer, 10);
	if (first_n)
	{
		aux = ft_substr(buffer, 0, first_n - buffer + 1);
		rest = ft_substr(buffer, first_n - buffer + 1, BUFFER_SIZE);
		free (rest);
		line = aux;
		free (aux);
		free (buffer);
		return (line);
	}
	else
	{
		aux = ft_strdup(buffer);
		free(buffer);
		//volver a llamar a gnl. Primero verificar si existe "rest"

		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read(fd, buffer, BUFFER_SIZE);
		rest = ft_strjoin(aux, buffer);
		free (aux);
		free(buffer);
		return (rest);

	}
	return (rest);	//no tiene q devolver buffer, lo he puesto para hacer pruebas
}
void leakss()
{
	system ("leaks a.out");
}

int	main()
{
	int fd;


	fd = open("el_quijote.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	atexit(leakss);
	return 0;
}


