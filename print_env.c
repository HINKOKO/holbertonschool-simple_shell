#include "main.h"

/**
 *main - prints the environnement using
 *global variable environ
 *Return: Always 0
 */

int print_env(char *cmd, char **args, char **env)
{
	unsigned int i = 0;

	(void)cmd;
	(void)args;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
