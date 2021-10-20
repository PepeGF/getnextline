/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:24:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/20 18:49:02 by josgarci         ###   ########.fr       */
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
//	static t_list	line;		idea posible hacerlo con listas

	BUFFER_SIZE = 1500;		//solo vale para prubas
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	first_n = ft_strchr(buffer, 10);
	if (first_n)
	{
		aux = ft_substr(buffer, 0, first_n - buffer + 1);
		rest = ft_substr(buffer, first_n - buffer + 1, BUFFER_SIZE);
		free (rest);
		free (buffer);
		free (aux);
		return (aux);
	}
	return (buffer);	//no tiene q devolver buffer, lo he puesto para hacer pruebas
}

int	main()
{
	int fd;

	fd = open("el_quijote.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	return 0;
}


