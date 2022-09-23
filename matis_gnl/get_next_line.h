#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

char	*strn_cpy(char *dest, char *source, int n);
int		search_line(char **line, char *buffer, int n);
int		str_len(char *str);
char	*str_concatenate(char *l1, char *l2);
char	*get_next_line(int fd);
void	ft_bzero(char *ptr, int n);

#endif