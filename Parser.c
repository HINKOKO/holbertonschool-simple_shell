#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

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
	return (0);
}
