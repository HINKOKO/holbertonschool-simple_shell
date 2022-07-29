#include "main.h"

char **shl_get_args(char *readLine)
{
	int bufsize = 0;
	char **tokens = malloc(sizeof(char*) * bufsize);
	char *token = NULL;

	if (!tokens)
	{
		perror("shl: allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(readLine, " ");

	while (token != NULL)
	{
		tokens[bufsize] = strdup(token);
		token = strtok(NULL, " ");
		bufsize++;
	}
	tokens[bufsize] = NULL;
	return (tokens);
}
