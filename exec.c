#include "main.h"

/**
 * exec - executes the command entered by the user
 * @buff: the command entered by the user
 */

void exec(char **buff)
{
	FILE *stream;

	stream = fopen(*buff, "r");
	if (stream == NULL)
	{
		perror("Error");
	}
	if (execve(buff[0], buff, NULL) == -1)
	{
		perror("Error");
	}
	fclose(stream);
}
