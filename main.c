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
			printf("$ ");
		line = get_line();
		buff = parse_line(line);
		if (strcmp(buff[0], "exit") == 0)
			break;
		else if (strcmp(buff[0], "env") == 0)
		{
			i = 0;
			while (env[i])
			{
				printf("%s\n", env[i]);
				i++;
			}
		}
		else
			create_process(buff, env);
	}
	return (0);
}
