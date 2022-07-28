#include "main.h"
#include "wordcount.c"

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
