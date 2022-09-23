#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char *strn_cpy(char *dest, char *source, int n);
int search_line(char **line, char *buffer, int n);

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *l1 = get_next_line(fd);
	printf("%s", l1);

	//while(l1 != NULL)
	//{
		l1 = NULL;
		l1 = get_next_line(fd);
		printf("%s", l1);
	//}
}
