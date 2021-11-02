/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separandofunciones.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/02 10:56:38 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split_line(char **rest,int first_n);

/*
char	*ft_readtext(int fd, int *first_n, char **rest)
{
	char	*buffer;
	char	*aux;

	while (first_n == -1)
	{
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		ft_bzero (buffer, BUFFER_SIZE + 1);
		if (!read (fd, buffer, BUFFER_SIZE))
			return (0);
	aux = ft_strjoin(*rest, buffer);
	buffer = 0;
	free(buffer);
	*rest = ft_strdup(aux);
	free(aux);
	*first_n = ft_strchr(rest, 10);
	}
}
*/

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	int			first_n;
	//char		*line;
	char		*aux;

	if (BUFFER_SIZE < 0 || fd <= 2)
		return (0);
	first_n = ft_strchr(rest, 10);
	//ft_readtext(fd, &first_n, &*rest);
	while (first_n == -1)
	{
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		ft_bzero (buffer, BUFFER_SIZE + 1);
		if (!read (fd, buffer, BUFFER_SIZE))
			return (0);
	aux = ft_strjoin(rest, buffer);
	buffer = 0;
	free(buffer);
	rest = ft_strdup(aux);
	free(aux);
	first_n = ft_strchr(rest, 10);
	/*
	if (rest[0] != '\n')
	first_n = ft_strchr(rest, 10);
	else
		break;
		*/
	}
/*
	line = ft_substr(rest, 0, first_n + 1);
	aux = ft_substr(rest, first_n + 1, ft_strlen(rest) - first_n - 1);
	free(rest);
	rest = ft_strdup(aux);
	free(aux);
	return(line);
*/
	return(ft_split_line(&rest, first_n));
}

char	*ft_split_line(char **rest,int first_n)
{
	char	*line;
	char	*aux;
	printf("rest:%s//SALTO->%i\n",*rest, first_n);
	line = ft_substr(*rest, 0, first_n + 1);
	printf("line:\n%s\n",line);
	aux = ft_substr(*rest, first_n + 1, ft_strlen(*rest) - first_n - 1);
	printf("aux:\n%s\n",aux);
	//free(*rest);
	*rest = ft_strdup(aux);
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

	fd = open("xlotr.txt", O_RDONLY);
	i = 1;
	if (LINEAS == 0)
		while (get_next_line(fd));
	else
		while (i <= LINEAS)
		{
			printf("Linea %i->%s",i,get_next_line(fd));
			printf("******************************************************\n");
			i++;
		}
			//printf(get_next_line(fd));
	/*
	while (i <= LINEAS)
	{
	printf("Linea %i->%s",i,get_next_line(fd));
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	*/
	/*
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
