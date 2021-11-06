/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/29 13:11:29 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	int			first_n;
	char		*line;
	char 		*aux;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_bzero(buffer, BUFFER_SIZE + 1);
	read(fd, buffer, BUFFER_SIZE);
	rest = ft_strjoin(buffer, rest);
	//rest = ft_substr(buffer, 0, BUFFER_SIZE + 1); SOLO VALE PARA LA 1ª VEZ
	printf("-----------------------------------\n");
	printf("Soy todo el buffer-> %s\n",rest);
	first_n = ft_strchr(rest, 10);
	line = ft_substr(rest, 0, first_n + 1);
	printf("-----------------------------------\n");
	printf("Soy la linea -> %s",line);
	aux = ft_substr(rest, first_n, BUFFER_SIZE - first_n);
	free(rest);
	rest = ft_substr(aux, 0, BUFFER_SIZE- first_n);
	printf("-----------------------------------\n");
	printf("Soy aux -> %s\n",aux);
	printf("-----------------------------------\n");
	printf("Soy rest tomado desde \\n-> %s\n",rest);
	printf("-----------------------------------\n");
	free (aux);
	free(buffer);
	free(line);
	return (line);
}

void leakss()
{
	system ("leaks a.out");
}

int	main()
{
	int fd;
	int i;

	atexit(leakss);

	fd = open("el_quijote.txt", O_RDONLY);
	i = 1;
//	while (get_next_line(fd))
//	{
		printf("Linea %i->%s", i, get_next_line(fd));
//		i++;
//	}
	//	get_next_line(fd);

	return 0;
}
