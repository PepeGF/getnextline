/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/19 18:56:11 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#define BUFFER_SIZE 1
//#define LINEAS 0

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
	{
		if (rest)
			free(rest);
		return (0);
	}
	else
	{
		return(ft_split_line(&rest, first_n));
	}
}

char	*ft_readtext(int fd, int *first_n, char **rest)
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
		if (lenread == -1 || (lenread == 0 && ft_strlen(*rest) == 0))
		{
			free (buffer);
			return (0);
		}
	aux = ft_strjoin(*rest, buffer);
	free(buffer);
		if (lenread < BUFFER_SIZE)
			*first_n = ft_strlen(aux);
	if (*rest && ft_strlen(*rest) > 0)
		free(*rest);
	*rest = ft_strdup(aux);
	free(aux);
	if (lenread == BUFFER_SIZE)
		*first_n = ft_strchr(*rest, 10);
	if (lenread == 0)
		*first_n = ft_strlen(*rest);
	}
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
	//free (aux);		//soluciona un leak
	return(line);
}

void leakss()
{
	system ("leaks a.out");
}

/*
int	main()

{
	int fd;
	int i;

	//atexit(leakss);

	//fd = open("/home/josgarci/getnextline/41_no_nl.txt", O_RDONLY);
	fd = open("5_no_nl", O_RDONLY);
	if (LINEAS == 0)
		while (get_next_line(fd));
	else
	{
		i = 1;
		while (i <= LINEAS)
		{
			printf("Linea %i->%s",i,get_next_line(fd));
//get_next_line(fd);
			i++;
		}
	}
	return 0;
}
*/

/*	**********PRINTS VARIOS:***************
	printf("%s\n",);
	printf("Buffer:\n%s\n",buffer);
	printf("aux:\n%s\n",aux);
	printf("rest:\n%s\n",rest);
	printf("line:\n%s\n",line);
	printf("%p\n",);
*/

