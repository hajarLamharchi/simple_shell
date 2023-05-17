#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always0
 */

int main(void)
{
	char *line = NULL;
	char **buff;
	int i = 0;
	pid_t pid;

	while (1)
	{
		line = print_prompt();
		if (line == NULL)
		{
			perror("Error");
			return (1);
		}
		printf("%s", line);
		buff = parse_input(line);
		if (buff == NULL)
		{
			perror("Error");
			free(line);
			return (1);
		}
		while (buff[i] != NULL)
		{
			printf("%s\n", buff[i]);
			free(buff[i]);
			i++;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		else if (pid == 0)
		{
			exec(buff);
		}
		else
		{
			wait(NULL);
		}

		free(buff);
		free(line);
	}
	return (0);
}
