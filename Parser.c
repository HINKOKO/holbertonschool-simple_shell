#include "shell.h"

/**
 * get_args - Function that creates token words
 * @buff: is the buffer which get token
 *
 * Return: Tokens
 */

char **get_args(char *buff)
{
	char **args = NULL;
	char *arg = NULL;
	int i = 0;

	args = malloc(sizeof(char *) * (wordcount(buff) + 1));
	if (!args)
		return (NULL);
	arg = strtok(buff, " ");

	while (arg != NULL)
	{
		args[i] = strdup(arg);
		arg = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	return (args);
}
/**
 * free_args - freeing the space allocated for the array of args
 * @args: array of args
 */
void free_args(char **args)
{
	int i = 0;

	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
