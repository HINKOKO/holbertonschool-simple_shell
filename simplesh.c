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
	char *buff = NULL;
	ssize_t nread = 0;
	size_t read = 0;

	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("> ");
		buff = NULL;
		nread = getline(&buff, &read, stdin);
		if (nread == -1)
		{
			if (buff)
				free(buff);
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			exit(EXIT_FAILURE);
		}
		else
		{
			executor(buff, env);
			free(buff);
		}
	}
	return (0);
}
