#include "main.h"

/**
 * create_process - create a new child process with fork
 * @buff: points to the command entered by the user
 * @env: environment
 * Return: 0 on succes 1 otherwise
 */

int create_process(char **buff, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		free(buff);
		perror("Error");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(buff[0], buff, env) == -1)
		{
			write(1, "./shell: No such file or directory\n", 50);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
