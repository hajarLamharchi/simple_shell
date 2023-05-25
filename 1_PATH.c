#include "main.h"

int path(void)
{
	char file_path[MAX_PATH_LENGTH];
	char *path;
	char *dir;
	char *line = NULL;
	int command_exists = 0;

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

			if (access(file_path, F_OK) == 0)
			{
				command_exists = 1;
				break;
			}

			dir = strtok(NULL, ":");
		}

		free(line);

		if (command_exists)
		{
			break;
		}
	}

	if (!command_exists)
	{
		printf("Command does not exist.\n");
	}

	return 0;
}

