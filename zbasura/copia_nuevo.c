#include "get_next_line.h"

char    *get_next_line(int fd)
{
        static char     *rest;
        char            *buffer;
        char            *aux;
        char            *line;
        int                     first_n;

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (0);
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
                return (0);
        ft_bzero(buffer, BUFFER_SIZE + 1);
        read(fd, buffer, BUFFER_SIZE);
        rest = ft_strjoin(rest, buffer);
        printf("Primer rest->%s\n",rest);
        //free(rest);//sin este free rest se llena de mierda
        first_n = ft_strchr(rest, 10);
        while (!first_n)
        {
        ft_bzero(buffer, BUFFER_SIZE + 1);
        read(fd, buffer, BUFFER_SIZE);
        rest = ft_strjoin(rest, buffer);
        printf("Mas y mas rest->%s\n",rest);
        free(buffer);
        first_n = ft_strchr(rest, 10);
        }
                aux = ft_substr(rest, 0, first_n + 1);
                line = aux;
                //free (aux);
                rest = ft_substr(rest, first_n + 1, BUFFER_SIZE - first_n);//rest = substr??
                //rest = aux;
                //free (buffer);
                return (line);
}

void leakss()
{
        system ("leaks a.out");
}

int     main()
{
        int fd;

//      atexit(leakss);

        fd = open("el_quijote.txt", O_RDONLY);
//      while (get_next_line(fd))
//              printf("Linea->%s",get_next_line(fd));
get_next_line(fd);
get_next_line(fd);
//              printf("Linea->%s",get_next_line(fd));

        return 0;
}

