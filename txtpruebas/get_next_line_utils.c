/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:52:09 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/25 16:27:18 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	x;

	if (str == 0)
		return (0);
	x = 0;
	while (*(str + x) != '\0')
		x++;
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	const char		*aux1;
	unsigned long	aux2;

	if (s == NULL)
		return (0);
	aux1 = s;
	aux2 = 0;
	if (c > 127)
		c = (unsigned char)c;
	while (aux1[aux2] != '\0')
	{
		if (aux1[aux2] == c)
			return (&((char *)aux1)[aux2]);
		aux2++;
	}
	if (aux1[aux2] == c)
		return (&((char *)aux1)[aux2]);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*aux1;
	const unsigned char	*aux2;
	unsigned long		aux3;

	aux1 = dest;
	aux2 = src;
	aux3 = 0;
	if (aux1 == NULL && aux2 == NULL)
		return (0);
	while (aux3 < n)
	{
		aux1[aux3] = aux2[aux3];
		aux3++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	char	*aux1;

	aux1 = s;
	while (n > 0)
	{
		*aux1 = '\0';
		aux1++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*aux1;

	aux1 = malloc(count * size);
	if (aux1 == NULL)
		return (0);
	ft_bzero(aux1, (count * size));
	return (aux1);
}
