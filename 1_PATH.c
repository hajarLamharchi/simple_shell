#include "main.h"
/**
 * path - function that handles path
 * Return: void
 */
int path(void)
{
	char file_path[MAX_PATH_LENGTH];
	char *path;
	char *dir;
	char *line = NULL;

	path = getenv("PATH");
	line = get_line();

	while (line != NULL)
	{
		dir = strtok(path, ":");

		while (dir != NULL)
		{
			strcpy(file_path, dir);
			strcat(file_path, "/");
			strcat(file_path, line);

			dir = strtok(NULL, ":");
		}

		free(line);
	}
	return (0);
}
