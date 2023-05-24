#include "main.h"

/**
 * get_line - gets the line entered by the user
 * Return: the line writen by the user
 */

char *get_line()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_char;
	int i = 0;

	n_char = getline(&line, &len, stdin);
	if (n_char == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = 0;
		i++;
	}
	return (line);
}
