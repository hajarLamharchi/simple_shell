#include "main.h"

/**
 * parse_input - tokenize the input
 * @s: the command entered by the user
 * Return: parsed input
 */

char **parse_input(char s[])
{
	char *d = " ";
	char **buff = NULL;
	int i = 0, j;
	char *token;
	int len = strlen(s);

	if (len == 0)
	{
		return (NULL);
	}

	buff = malloc((len + 1) * sizeof(char *));
	if (buff == NULL)
	{
		return (NULL);
	}

	token = strtok(s, d);
	while (token != NULL)
	{
		buff[i] = malloc(strlen(token) + 1);
		if (buff[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(buff[j]);
			free(buff);
			return (NULL);
		}
		strcpy(buff[i], token);
		token = strtok(NULL, d);
		i++;
	}
	buff[i] = NULL;
	return (buff);
}
