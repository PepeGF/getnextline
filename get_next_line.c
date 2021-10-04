/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:24:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/04 20:25:29 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t count, size_t size);

char	*get_next_line(ind fd)
{
	int		BUFFER_SIZE
	char	*buffer;
	t_list	*line;

	BUFFER_SIZE = 10;
	buffer = (char *)ft_calloc(BUFFER_SIZE)

	line->content = read(fd, buffer, BUFFER_SIZE);

	return (line->content); //no es buffer lo que tiene que devovler
}

void    *ft_calloc(size_t count, size_t size)
{
        void    *ptr;
		size_t	i;

        ptr = (void *)malloc(size * count);
        if (ptr == NULL)
                return (0);
		i = 0;
		while (i < size)
		{
			ptr[i] = '\0';
			i++
		}
        return (ptr);
}
