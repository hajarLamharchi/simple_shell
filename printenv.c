#include "main.h"

/**
 * print_env - prints the environment variables
 * @env: environment
 * Return: nothing
 */

void print_env(char **env)
{
	unsigned int i = 0;

	while (env[i])
	{
		write(1, env[i], strlen(env[i]));
		write(1, "\n", 2);
		i++;
	}
}
