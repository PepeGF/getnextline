/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separandofunciones.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/04 13:40:23 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1
#define LINEAS 1

char	*ft_split_line(char **rest,int first_n);
char	*ft_readtext(int fd, int *first_n, char **rest);

char	*get_next_line(int fd)
{
	static char	*rest;
	int			first_n;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd,0,0) == -1)
		return (0);
	first_n = ft_strchr(rest, 10);
	if (!ft_readtext(fd, &first_n, &rest))
		return (0);
	else
	{
		return(ft_split_line(&rest, first_n));
	}
}

char	*ft_readtext(int fd, int *first_n, char **rest)
{
	char	*buffer;
	char	*aux;

	while (*first_n == -1)
	{
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		ft_bzero (buffer, BUFFER_SIZE + 1);
		if (!read (fd, buffer, BUFFER_SIZE))
		{
			free (buffer);
			return (0);
		}
	//printf("Buffer:\n%s\n",buffer);
	aux = ft_strjoin(*rest, buffer);
	//printf("rest:%s\naux:%s\n",*rest, aux);
	//printf("aux:\n%s\n",aux);
	free(buffer);
	if (*rest && ft_strlen(*rest) > 0)
		free(*rest);
	*rest = ft_strdup(aux);
	free(aux);
	*first_n = ft_strchr(*rest, 10);
	}
	//printf("Dir **rest->%p\n",*rest);
	//printf("Dir buffer->%p\n",buffer);
	//printf("Dir aux->%p\n",aux);
	return(*rest);
}

char	*ft_split_line(char **rest,int first_n)
{
	char	*line;
	char	*aux;

	line = ft_substr(*rest, 0, first_n + 1);
	aux = ft_substr(*rest, first_n + 1, ft_strlen(*rest) - first_n - 1);
	/*
	//free(*rest); //si se libera pierde informacion
	*rest = ft_strdup(aux);
	free(aux);
	*/
	
	free (*rest);
	*rest = aux;
	//printf("rest:\n%s\n",*rest);
	//free (aux);
/*	
	printf("Dir **rest->%p\n",*rest);
	printf("Dir line->%p\n",line);
	printf("Dir aux->%p\n",aux);
*/
	//free (line);
	return(line);
}

void leakss()
{
	system ("leaks a.out");
}


int	main()

{
	int fd;
	int i;

	//atexit(leakss);

	//fd = open("/home/josgarci/getnextline/41_no_nl.txt", O_RDONLY);
	fd = open("41_no_nl.txt", O_RDONLY);
	i = 1;
	if (LINEAS == 0)
		while (get_next_line(fd));
	else
		while (i <= LINEAS)
		{
			//printf("Linea %i->%s",i,get_next_line(fd));
get_next_line(fd);
			i++;
		}
	return 0;
}


/*	**********PRINTS VARIOS:***************
	printf("%s\n",);
	printf("Buffer:\n%s\n",buffer);
	printf("aux:\n%s\n",aux);
	printf("rest:\n%s\n",rest);
	printf("line:\n%s\n",line);
	printf("%p\n",);
*/

