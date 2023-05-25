#include "main.h"
/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vector
 * @env: environment
 * Return: Always 0
 */
int main(__attribute__((unused)) int argc,
		__attribute__((unused)) char **argv,
		char **env)
{
	char *line;
	char **buff;
	unsigned int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		line = get_line();
		if (line == NULL)
		{
			free(line);
			break;
		}
		buff = parse_line(line);
		if (buff == NULL)
		{
			free_buff(buff);
			free(line);
			continue;
		}
		if (strcmp(buff[0], "exit") == 0)
			break;
		else if (strcmp(buff[0], "env") == 0)
		{
			i = 0;
			while (env[i])
			{
				write(1, env[i], strlen(env[i]));
				write(1, "\n", 2);
				i++;
			}
		}
		else
			create_process(buff, env);
		free_buff(buff);

	}
	free_buff(buff);
	free(line);
	return (0);
}
