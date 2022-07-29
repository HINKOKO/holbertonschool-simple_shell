#include "main.h"

/**
 * main - simple shell
 * @av: simple shell
 * @env: simple shell
 * @ac: simple shell
 * Return: simple shell
 */

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *buff = NULL, **args = NULL;
	ssize_t nread = 0;
	size_t read = 0;
	pid_t child = 0;

	(void)av;
	(void)env;

	while (1)
	{
		printf("> ");
		nread = getline(&buff, &read, stdin);
		if (nread != -1)
		{
			child = fork();
			if (child == 0)
			{
				args = get_args(buff);
				if ((execve(args[0], args, env)) == -1)
				{
					perror(args[0]);
					exit(EXIT_FAILURE);
				}
			}
			else if (child > 0)
				wait(NULL);
			else
			{
				free(buff);
				return (1);
			}
		}
		else
		{
			free(buff);
			return (1);
		}
	}
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
