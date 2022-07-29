#include "main.h"

/**
 * main - display prompt and manage input
 * @ac: argument count
 * @av: one-dim array argument
 * @env: environnement is important
 * Return: 0 success
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

		if (isatty(STDIN_FILENO))
			printf("> ");
		nread = getline(&buff, &read, stdin);
		if (nread != -1)
		{
			args = get_args(buff);
			if (args[0])
			{
				child = fork();
				if (child == 0)
				{
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
					free_args(args);
					return (1);
				}
			}
			free_args(args);
		}
		else
		{
			free(buff);
			return (0);
		}
	}
	return (0);
}
