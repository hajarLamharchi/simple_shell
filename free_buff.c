#include "main.h"
/**
 * free_buff - frees a buffer
 * @buff: the buffer to free
 * return: nothing
 */

void free_buff(char **buff)
{
	unsigned int i = 0;

	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}
