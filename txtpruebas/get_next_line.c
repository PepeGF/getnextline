/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:50:53 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/26 11:59:08 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_str(char *str);
static char	*get_extra(char *str);
static char	*read_str(int fd, char *prevstr);

char	*get_next_line(int fd)
{
	char		*str;
	char		*str2;
	static char	*aux;

	str2 = 0;
	str = read_str(fd, aux);
	//printf("Frase leida--> %s\n",str);
	aux = get_extra(str);
	//printf("Frase extra--> %s\n",aux);
	str = get_str(str);
	//printf("Frase a devolver--> %s\n",str);
	return (str);
}

static char	*read_str(int fd, char *prevstr)
{
	char	*str;
	char	*aux;
	int		tam;

	if (ft_strchr(prevstr, '\n') != 0 && ft_strlen(prevstr) != 0)
		return (prevstr);
	tam = ft_strlen(prevstr);
	str = calloc (sizeof(char), (BUFFER_SIZE + tam + 1));
	ft_memcpy(str, prevstr, tam);
	prevstr = 0;
	//printf("Base antes de la lectura --> %s\n",str);
	if (read(fd, str + tam, BUFFER_SIZE) == 0)
		return (str);
	//printf("Primera lectura --> %s\n",str);
	while (ft_strchr(str, '\n') == 0)
	{
		//printf("inicio de bucle --> %s\n", str);
		tam = ft_strlen(str);
		aux = calloc (sizeof(char), (BUFFER_SIZE + tam));
		ft_memcpy(aux, str, tam);
		//printf("Frase al pasarla al aux --> %s\n", aux);
		if (read(fd, aux + tam, BUFFER_SIZE) == 0)
			break ;
		//printf("Frase tras lectura de bucle --> %s\n", aux);
		str = aux;
	}
	//printf("Texto devuelto --> %s\n", str);
	return (str);
}

static char	*get_str(char *str)
{
	char	*aux;

	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strchr(str, '\n') == 0)
		return (str);
	aux = calloc(sizeof(char), \
	ft_strlen(str) - ft_strlen(ft_strchr(str, '\n') + 1));
	if (aux == 0)
		return (0);
	aux = ft_memcpy(aux, str, ft_strlen(str) - ft_strlen(ft_strchr(str, '\n')));
	return (aux);
}

static char	*get_extra(char *str)
{
	char	*extra;

	extra = NULL;
	if (ft_strchr(str, '\n') != 0)
	{
		extra = calloc(sizeof(char), ft_strlen(ft_strchr(str, '\n')));
		if (extra == 0)
			return (0);
		extra = ft_strchr(str, '\n') + 1;
	}
	return (extra);
}

int	main(void)
{
	int	fd;
	int	cont;
	char *str;

	cont = 0;
	fd = open("Leeme.txt", 0);
	while(cont < 50)
	{
	str = get_next_line(fd);
	printf("%s\n", str);
	//printf("Tamaño de la frase %i",ft_strlen(str));
	cont++;
	free(str);
	}
	close(fd);
}
//gcc -fsanitize=address -Wall -Werror -Wextra -D BUFFER_SIZE=14 get_next_line.c get_next_line_utils.c && ./a.out 

//gcc -Wall -Werror -Wextra -D BUFFER_SIZE=7 get_next_line.c get_next_line_utils.c && ./a.out 

//gcc -Wall -Werror -Wextra -D BUFFER_SIZE=15 get_next_line.c get_next_line_utils.c && ./a.out 

//gcc -Wall -Werror -Wextra -D BUFFER_SIZE=17 get_next_line.c get_next_line_utils.c && ./a.out 