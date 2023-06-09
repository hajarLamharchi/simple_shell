#include "main.h"

/**
 * create_process - create a new child process with fork
 * @buff: points to the command entered by the user
 * Return: 0 on succes 1 otherwise
 */

int create_process(char **buff)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		free_buff(buff);
		perror("Error");
		return (1);
	}
	else if (pid == 0)
	{
		if (execvp(buff[0], buff) == -1)
		{
			write(1, "./shell: No such file or directory\n", 50);
		}
		exit(EXIT_FAILURE);
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
