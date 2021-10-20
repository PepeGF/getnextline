/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:24:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/20 12:24:52 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		BUFFER_SIZE;	//solo vale para pruebas
	char		*buffer;
	char		*aux;
//	static char	*rest;
	char		*first_n;
//	static t_list	line;		idea posible hacerlo con listas

	BUFFER_SIZE = 1500;		//solo vale para prubas
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	first_n = ft_strchr(buffer, 10);
	printf("%p\n",first_n);
	printf("%p\n",buffer);
	printf("%li\n",first_n-buffer);
	if (first_n)
	{
		aux = ft_substr(buffer, 0, first_n - buffer + 1);
		free (buffer);
		return (aux);
	}
/*	if (ft_strchr(buffer, 10) != buffer + BUFFER_SIZE)
	{
		rest = malloc (((buffer + BUFFER_SIZE) - ft_strchr(buffer, 10) + 1) * sizeof(char));
		rest = ft_substr(buffer, necesito encontrar la posicion del primer \n,
	}
*/

	return (buffer);	//no tiene q devolver buffer, lo he puesto para hacer pruebas
}

int main()
{
	int fd;

//	atexit()

	fd = open("el_quijote.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	return 0;
}


