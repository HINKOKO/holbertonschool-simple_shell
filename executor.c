#include "main.h"

/**
 *
 *
 */

void executor(char *buff, char **env)
{
	pid_t child;
	char **args = NULL;
	char *fullpath = NULL, *PATH;
	args = get_args(buff);
	if (args[0])
	{
		/**
		 *(int)check_builtin(args[0], args, env)
		 *if == 0
		 *free(args)
		 *return(SUCCESS)
		 */
		PATH = strdup(getenv("PATH"));
		fullpath = pathfinder(args[0], PATH);
		free(PATH);
		child = fork();
		if (child == 0)
		{
			if ((execve(fullpath, args, env)) == -1)
			{
				printf("hsh: %s: command not found\n", args[0]);
				free_args(args);
				free(fullpath);
				return;
			}
		}

		else if (child > 0)
			wait(NULL);
		else
		{
			free_args(args);
			free(fullpath);
			exit(EXIT_FAILURE);
		}
		if (fullpath)
			free(fullpath);
	}
	free_args(args);
}
