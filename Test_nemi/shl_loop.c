#include "main.h"

void shl_loop()
{
	char *readLine;
	char **args;
	int status;

	do {
		printf("> ");
		readLine = shl_read_line();
		args = shl_get_args(readLine);
		status = shl_execute(args);

		free(readLine);
		free(args);
	} while (status);
}
