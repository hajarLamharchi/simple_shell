#include "main.h"
/**
 * parse_line - tokenize the input
 * @s: the command entered by the user
 * Return: parsed input
 */
char **parse_line(char s[])
{
	char *d = " ", *token;
	char **buff = NULL;
	int i = 0, j, k = 0;
	int len = strlen(s);

	if (len == 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	buff = malloc((len + 1) * sizeof(char *));
	if (buff == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(s, d);
	while (token != NULL)
	{
		while (token[k])
		{
			if (token[k] == '\n')
				token[k] = '\0';
			k++;
		}
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
