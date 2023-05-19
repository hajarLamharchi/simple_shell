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

	while (1)
	{
		printf("$ ");
		line = get_line();
		buff = parse_input(line);
		create_process(buff);

		free(buff);
		free(line);
	}
	return (0);
}
