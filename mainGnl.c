/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainGnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:53:01 by potero-d          #+#    #+#             */
/*   Updated: 2021/11/24 16:56:10 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
#include <fcntl.h>
/*
int				main()
{
	int			fd;
	char		*str;
	int			i;

	i = 0;
	fd = open("lotr.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
		free(str);
	return (0);
}
*/

int	main()
{
	int			fd;
	char		*str;
	int			i;

	i = 0;
	fd = open("lotr.txt", O_RDONLY);
// 	get_next_line(fd, &str);
//	printf("%s", str); 
	while ((str = get_next_line(fd)))
	{
       //printf("line %i=>%s", i + 1, str);
		free(str);
		//i++;
	}
	system("leaks a.out");
	return (0);
}
/*
int	main(void)
{
	int	fd;
	char	*line;
	fd = open(FILEPATH, O_RDONLY);
	line = get_next_line(fd);
	line[0] = '0';
	//printf("%s",line);
	free (line);
	line = get_next_line(fd);
	//printf("%s",line);
	free (line);
	//line = get_next_line(fd);
	//printf("%s",line);
	//free (line);
	close (fd);
	return (0);
}
*/
