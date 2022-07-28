#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define IN 1
#define OUT 0

size_t wordcount(char *s)
{
	size_t i = 0, w = 0;
	int flag;

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

int main(int ac, char **av, char **env)
{
	char *buff = NULL;
	char **args = NULL;
	ssize_t nread = 0;
	size_t read = 0;
	pid_t child;

	(void)ac;
	(void)av;
	(void)env;

	while (1)
	{
		printf("> ");
		if ((nread = getline(&buff, &read, stdin)) != -1)
		{
			args = (char **)malloc(sizeof(char *) * (wordcount(buff) + 1));

			child = fork();
			if (child == 0)
			{
				args = get_args(buff);
				if ((execve(args[0], args, env)) == -1)
				{
					perror(args[0]);
					printf("no stuff like that");
					exit(EXIT_FAILURE);
				}
				else
				{
					execve(args[0], args, env);
				}
			}
			else if (child > 0)
			{
				wait(NULL);
			}
			else
			{
				perror("Failed to run\n");
				free(buff);
				exit(1);
			}
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
