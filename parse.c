#include "main.h"
/**
 * parse_line - tokenize the input
 * @s: the command entered by the user
 * Return: parsed input
 */
char **parse_line(char s[])
{
	char *d = " \t\n\r\a", *token;
	char **buff = NULL;
	int i = 0, k;
	int len = strlen(s);


	if (len == 0)
		return (NULL);
	buff = malloc((len + 1) * sizeof(char *));
	if (buff == NULL)
	{
		free(buff);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(s, d);
	while (token != NULL)
	{
		k = 0;
		while (token[k] != '\0')
		{
			if (token[k] == '\n')
				token[k] = '\0';
			k++;
		}
		if (k > 0)
		{
			buff[i] = malloc(strlen(token) + 1);
			if (buff[i] == NULL)
			{
				free_buff(buff);
				return (NULL);
			}
			strcpy(buff[i], token);
			token = strtok(NULL, d);
			i++;
		}
	}
	buff[i] = NULL;
	return (buff);
}
