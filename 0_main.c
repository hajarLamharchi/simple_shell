#include "main.h"
/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vector
 * @env: environment
 *
 * Return: Always0
 */

int main(__attribute__((unused)) int argc,
		__attribute__((unused)) char **argv,
		char **env)
{
	char *line = NULL;
	char **buff;
	unsigned int i = 0;
	char file_path[MAX_PATH_LENGTH];
	char* path;
	char* dir;

	while (1)
	{
		putchar('$');
		line = get_line();
		buff = parse_input(line);
		if (strcmp(buff[0], "exit") == 0)
		{
			break;
		}
		else if (strcmp(buff[0], "env") == 0)
		{
			while (env[i] != NULL)
			{
				printf("%s\n", env[i]);
				i++;
			}
		}
		else
		{
			create_process(buff);
		}

		path = getenv("PATH");
		dir = strtok(path, ":");

		while (dir != NULL) {

			strcpy(file_path, dir);
			strcat(file_path, "/");
			strcat(file_path, line);

		}
		free(buff);
		free(line);
	}
	return (0);
}

