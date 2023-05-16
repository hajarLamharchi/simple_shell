#include "main.h"

/**
 * exec - executes the command entered by the user
 * @buff: the command entered by the user
 */

void exec(char **buff)
{
	if (execve(buff[0], buff, NULL) == -1)
	{
		perror("Error");
	}
}
