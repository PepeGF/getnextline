/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2022/05/04 20:19:30 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split_line(char **rest, int first_n);
char	*ft_readtext(int fd, int *first_n, char **rest, size_t *lenrest);
char	*ft_fill_buffer(char *buffer, int *lenread, int fd);

char	*get_next_line(int fd)
{
	static char	*rest;
	int			first_n;
	size_t		lenrest;

	//gestion errores entrada
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
		return (0);
	//medir longitud de lo almacenado en la var estatica
	lenrest = ft_strlen_gnl(rest);
	//busca si hay salto de línea en lo almacenado
	first_n = ft_strchr_gnl(rest, 10);
	//si hay salto de línea separa la línea de lo demás con la funcion split line
	if (first_n != -1)
		return (ft_split_line(&rest, first_n));
	//si no hay salto de línea tiene que ir a la función de leer
	if (!ft_readtext(fd, &first_n, &rest, &lenrest))
	{	//si devuelve 0 es que no ha leído nada y no había nada en rest
		if (rest)
			free(rest);
		return (0);
	}
	else //una vez ha leido hasta encontrar salto o acabar el archivo separa la linea
		return (ft_split_line(&rest, first_n));
}

char	*ft_readtext(int fd, int *first_n, char **rest, size_t *lenrest)
{
	char	*buffer;
	char	*aux;
	int		lenread;

	while (*first_n == -1)//lee hasta que encuentre salto de linea (o nos inventemos uno)
	{
		buffer = ft_fill_buffer(buffer, &lenread, fd); //lee y rellena el buffer, tb almecena la longitud de lo leído
		if (lenread == -1 || (lenread == 0 && *lenrest == 0)) //==-1 es que no hay mas para leer y el resto es que no ha leido nada y no habia almacenado nada
		{
			free (buffer);//para evitar leak, al menos un nulo tiene guardado
			return (0);
		}
		*lenrest += lenread; //actualiza el valor de la longitud de la estatica, pero creo q se podría hacer después
		*first_n = ft_strchr_gnl(buffer, 10); //busca si en lo leido hay un salto de linea
		if (*first_n != -1)//si no hay salto de linea actualiza el valor del salto de linea a lo que habia + lo leido
			*first_n = *first_n + *lenrest - lenread - 0;//como se actualizo el valor en la linea 60 hay que restar lo añadido
		aux = ft_strjoin_gnl(*rest, buffer);//junta lo leido a lo que había en la estatica
		free(buffer);//ya no hace falta el buffer, su info está en aux
		if (*rest)// idem rest, pero en la primera llamada la funcion rest=NULL
			free(*rest);
		*rest = aux;//se redirige rest a la dirección de aux (para la siguiente vez q se llame a la función)
		if ((*first_n == -1 && lenread < BUFFER_SIZE) || lenread == 0) //si ha llegado al final del archivo y no hay salto
			*first_n = *lenrest;//nos "inventamos" un salto de linea al final para la función de split, esa necesita sí o sí un indice del salto de línea
	}
	return (*rest);
}

char	*ft_fill_buffer(char *buffer, int *lenread, int fd)//ojo al puntero al entero, vamos a modificar su valor
{
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero_gnl (buffer, BUFFER_SIZE + 1);//ponemos todo a cero por si no lo rellena entero estar seguros de que el string acaba en nulo
	*lenread = read (fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char	*ft_split_line(char **rest, int first_n)
{
	char	*line;
	char	*aux;

	line = ft_substr_gnl(*rest, 0, first_n + 1);//coge desde el principio una longitud salto de linea  + 1 - 0(inicio)
	aux = ft_substr_gnl(*rest, first_n + 1, ft_strlen_gnl(*rest) - first_n - 1);//coge desde salto+1 una longitud de 
			//longitud statica-ubicación salto linea(a estas alturas first_n puede venir de buffer o de rest) - 1(por el siguiente al salto)
	free (*rest);//libera rest
	*rest = aux;//para apuntarlo a lo q queda después del salto de linea
	return (line);
}
