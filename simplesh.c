#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

size_t wordcount(char *s)
{
	size_t i = 0, w = 0;
	int flag = OUT;

	while (s && s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			if (s[i] == '\n')
				s[i] = '\0';
			flag = OUT;
		}
		else if (flag == OUT)
		{
			flag = IN;
			w++;
		}
		i++;
	}
	return (w);
}

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
