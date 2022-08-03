#include "main.h"

/**
 *
 *
 *
 */

int (*check_builtin(char *command))(char *cmd, char **args, char **env)
{
	int i;
	built_in k[] = {
		{"exit", new_exit},
		{NULL, NULL},
	};

	for (i = 0; k[i].command != NULL; i++)
	{
		if (strcmp(command, k[i].command) == 0)
			return (k[i].f);
	}
	return (NULL);
}
