#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int		file_descrip;
	char	*path_file;
	char	*buffer;

	path_file = "archivoWololo.txt";

	file_descrip = open (path_file, O_RDONLY);
	printf("fd-> %i\n",file_descrip);
	buffer = (char *)malloc(BUFFER_SIZE);
	read (file_descrip, buffer, BUFFER_SIZE);
	printf("%s\n",buffer);
	free (buffer);

	return (0);
}
