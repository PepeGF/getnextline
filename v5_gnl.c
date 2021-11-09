/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v5_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/09 13:21:09 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* estos define los pongo para el script de debug
 */
#define BUFFER_SIZE 1
#define LINEAS 0

char	*ft_split_line(char **rest, int first_n);
char	*ft_readtext(int fd, int *first_n, char **rest);
char	*ft_strdup(const char *s1);

/* esta funcion es solo para gestionar las llamadas y devolver la línea o
 * un error (0) si lo hubiere
 */

char	*get_next_line(int fd)
{
	static char	*rest;
	int			first_n;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)//gestión de errores de entrada
		return (0);
	first_n = ft_strchr(rest, 10);//localiza el salto de línea en la estática
	if (!ft_readtext(fd, &first_n, &rest))
		return (0);
	else
		return (ft_split_line(&rest, first_n));
}

/* en esta funcion se va comprobando si hay salto de linea en la estática,
 * si no hay prepara un buffer para la lectura del archivo,
 * depués lee el archivo
 * añade lo leído a la variable estática con join
 * se hace un poco de gestión de memoria
 * y se vuelve a comprobar si después de hacer join hay salto
 * y si lo hay devuelve el resto y aunque no lo devuelve
 * también se modifica el valor de la posición del salto.
 * Si llega al final del archivo (lenread < BS) se asigna un salto de linea
 * "ficticio" al final del archivo. Esto último no tengo claro que sea la
 * solución al problema del segfault al final del archivo
 */

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
//este if es para cuando no hay nada que leer, en teoría solo puede entrar en el
//if si no lee nada y además no hay resto
//esta última condición la pongo xq en la penúltima lectura podría leer justo
//hasta el EOF, pero en ese caso sí habría resto y entraría en el siguiente if
		if (lenread == 0 && !rest)
		{
			free (buffer);
			return (0);
		}
//este if es para para comprobar q ha llegado al final del archivo
//y "crear" un salto de línea ficticio al final del archivo
		if (lenread < BUFFER_SIZE)
			*first_n = ft_strlen(rest);
		aux = ft_strjoin(*rest, buffer);
		free(buffer);
//este if lo ha puesto Alberto, no me convence la segunda condicion del if
//es para mejorar la ejecución y liberar rest para evitar la sobreescritura
//de su dirección de memoria y causar leak
			if (*rest && ft_strlen(*rest) > 0)
			free(*rest);
		*rest = ft_strdup(aux);
		free(aux);
		*first_n = ft_strchr(*rest, 10);
	}
	return (*rest);
}
/* 
 * Esta función coge todo el contenido de la estática y lo separa en 2
 * la primera parte sería la línea con salto incluido
 * la segunda parte sería todo lo de después del salto de línea
 */
char	*ft_split_line(char **rest, int first_n)
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
	free (aux);
	return (line);
}

/* Queda hueco para una función más */

/* Esta está aquí porque no cabe en _utils.c */
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	lens1;
	int		i;

	lens1 = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (lens1 + 1));
	if (ptr == NULL)
		return (0);
	ptr[lens1] = 0;
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

/*
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
	fd = open("41_no_nl", O_RDONLY);
	if (LINEAS == 0)
		while (get_next_line(fd));
	else
	{
		i = 1;
		while (i <= LINEAS)
		{
			//printf("Linea %i->%s",i,get_next_line(fd));
get_next_line(fd);
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
