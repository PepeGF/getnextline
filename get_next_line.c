/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:24:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/19 14:00:46 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int		BUFFER_SIZE;
	char	*buffer;
	static char *rest;
//	static t_list	line;		idea posible hacerlo con listas

	line = NULL;
	BUFFER_SIZE = 15;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));	//creo que hay que añadir el +1 para que el buffer tenga un nulo al final
	read(fd, buffer, BUFFER_SIZE);
	if (ft_strchr(buffer, 10))


	return (buffer);	//no tiene q devolver buffer, lo he puesto para hacer pruebas
}

int main()
{
	int fd;

	fd = open("archivoWololo.txt", O_RDONLY);
	printf ("fd->%i\n",fd);
	get_next_line(fd);
	return 0;
}
