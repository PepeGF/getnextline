#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int		file_descrip;
	char	*path_file;
	char	buffer[50];

	path_file = "archivoWololo.txt";

	file_descrip = open (path_file, O_RDONLY);
	printf("fd-> %i\n",file_descrip);
	read (file_descrip, buffer, 10);
	printf("%s\n",buffer);

	return (0);
}
