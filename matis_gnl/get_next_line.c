#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *strn_cpy(char *dest, char *source, int n);
int search_line(char **line, char *buffer, int n);
int str_len(char *str);
char *str_concatenate(char *l1, char *l2);
void	ft_bzero(char *ptr, int n);


char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*save = NULL;
	char		*l1 = NULL;
	char		*l2 = NULL;
	int			err;

	if (save && search_line(&l1, save, BUFFER_SIZE)==1)
		return l1;
	else
	{
		ft_bzero(buffer, BUFFER_SIZE);
		err = read(fd, buffer, BUFFER_SIZE);
		while (search_line(&l2, buffer, BUFFER_SIZE)==0 && err > 0)
		{
			if (l1)
				l1 = str_concatenate(l1,l2);
			else
				l1 = l2;
			ft_bzero(buffer, BUFFER_SIZE);
			err = read(fd, buffer, BUFFER_SIZE);
		}
		if (err > 0)
		{
			if (l1)
				l1 = str_concatenate(l1,l2);
			else
				l1 = l2;
			save = buffer;
		}
		else	
			return NULL;
	}
	return(l1);
}

char *strn_cpy(char *dest, char *source, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return dest;
}

int search_line(char **line, char *buffer, int n)
{
	int i;
	int j;

	i = 0;
	while (buffer[i] == 0 && i < n)
	{
		i++;
	}
	if (i == n)
		return(0);
	else
	{
		j = 0;
		while (buffer[i + j] && buffer[i + j - 1] != '\n' && i + j < n)
		{
			j++;
		}
		*line = malloc((j + 1) * sizeof(line));
		strn_cpy(line[0], (buffer + i),j);
		ft_bzero(buffer + i, j);
		line[0][j] = 0;
		if(line[0][j-1] == '\n')
			return 1;
		return 0;
	}
}

int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

char *str_concatenate(char *l1, char *l2)
{
	char *l3 = NULL;
	int len1;
	int len2;

	len1 = str_len(l1);
	len2 = str_len(l2);
	l3 = malloc((len1 + len2 + 1) * sizeof(l3));
	strn_cpy(l3, l1, len1);
	free(l1);
	l1 = NULL;
	strn_cpy(l3+len1, l2, len2);
	free(l2);
	l2 = NULL;
	l3[len1 + len2] = '\0';
	return l3;
}

/* int main()
{
	int fd;
	char *str;
	int i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%d %s",i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return 0;
} */
