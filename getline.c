#include "main.h"

/**
 * get_line - prints a prompt and wait for the user to enter a command
 * Return: the line writen by the user
 */

char *get_line()
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
