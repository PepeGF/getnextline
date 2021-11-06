/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maspruebas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/01 08:46:42 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	int			first_n;
	char		*line;
	char		*aux;

	first_n = ft_strchr(rest, 10);
	if (!first_n)
	{
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		ft_bzero (buffer, BUFFER_SIZE + 1);
		read (fd, buffer, BUFFER_SIZE);
	}
	aux = ft_strjoin(rest, buffer);
	if (buffer)
	{
		buffer = 0;
		free (buffer);
	}
	if (rest)
		free (rest);
	rest = ft_strdup(aux);
	free (aux);
	first_n = ft_strchr(rest, 10);
	line = ft_substr(rest, 0, first_n + 1);
	aux = ft_substr(rest, first_n + 1, ft_strlen(rest) - first_n - 1);
	free(rest);
	rest = ft_strdup(aux);
	free(aux);
	return(line);
}
/*	**********PRINTS VARIOS:***************
	printf("%s\n",);
	printf("Buffer:\n%s\n",buffer);
	printf("aux:\n%s\n",aux);
	printf("rest:\n%s\n",rest);
	printf("line:\n%s\n",line);
	printf("%p\n",);
 *
*/
/*
void leakss()
{
	system ("leaks a.out");
}
*/

int	main()
{
	int fd;
	int i;

//	atexit(leakss);

	fd = open("el_quijote.txt", O_RDONLY);
	i = 1;
	i *= 1;
	printf("Linea %i->%s",i,get_next_line(fd));
//	while (get_next_line(fd))
/*	while (i <= LINEAS)
	{
	printf("Linea %i->%s",i,get_next_line(fd));
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
	printf("Primera llamada\n---------------\n");
		printf("Linea 1->%s", get_next_line(fd));
	printf("Segunda llamada\n");
		printf("Linea 2->%s", get_next_line(fd));
		
		i++;
	}
	//	get_next_line(fd);
*/
	return 0;
}
