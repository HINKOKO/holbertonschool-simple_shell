#include "main.h"

char *shl_read_line(void)
{
	size_t position = 0;
	size_t buffSize = 32;
	unsigned int characters = '\0';
	char *buffer = malloc(sizeof(char) * buffSize);

	if (!buffer)
	{
		perror("shl: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* read a character */
		characters = getline(&buffer, &buffSize, stdin);
		if (getline(&buffer, &buffSize, stdin) == -1)
			{
				if (feof(stdin))
					exit(EXIT_SUCCESS);
				else
				{
					perror("readline");
					exit(EXIT_FAILURE);
				}
			}
		/* If we hit EOF, replace it with a null charatcer and return */
		if (characters == EOF || characters == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = characters;
	}
	return (buffer);
}
