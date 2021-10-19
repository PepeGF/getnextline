/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:21:43 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/19 13:17:43 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
	char			*line;
	struct s_list 	*next;
} t_list;

void    *ft_calloc(size_t count, size_t size);
char    *ft_strchr(const char *s, int c);
void    ft_putstr(char *s);


#endif
