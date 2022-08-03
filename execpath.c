#include "shell.h"

/**
 *exec_path - search command along the PATH and execute it
 *@args: array of arguments passed to stdin
 *@env: array of strings of env
 *Return: 0 for success, 134 for exiting
 */

int exec_path(char **args, char **env)
{
	pid_t child;
	char *fullpath = NULL, *PATH;

	PATH = strdup(getenv("PATH"));
	if (!PATH)
	{
		execve(args[0], args, env);
	}
	else
	{
		fullpath = pathfinder(args[0], PATH);
		free(PATH);
		child = fork();
		if (child == 0)
		{
			if ((execve(fullpath, args, env)) == -1)
			{
				write(STDERR_FILENO, "hsh: ", 6);
				write(STDERR_FILENO, args[0], strlen(args[0]));
				write(STDERR_FILENO, ": not found\n", 13);
				free(fullpath);
				return (134);
			}
		}

		else if (child > 0)
			wait(NULL);
		else
		{
			free(fullpath);
			return (134);
		}
	}
	if (fullpath)
		free(fullpath);
	return (0);
}
