/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:59:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/19 14:00:40 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *)malloc(size * count);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < size * count)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
	{
		printf("Primer salto->%i\n",i);			//añadido para pruebas
		return ((char *)s + i);
	}
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && s[i] != 10) //añadido aquí el && salto de línea
	{
		write(1, &s[i], sizeof(char));
		i++;
	}
}
