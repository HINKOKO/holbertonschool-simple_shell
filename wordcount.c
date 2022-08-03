#include "shell.h"

/**
 * wordcount - Function that create word token
 *
 * @s: is the string to make token from
 * Return: the tokens
 */

size_t wordcount(char *s)
{
	size_t i = 0, w = 0;
	int flag = OUT;

	while (s && s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			if (s[i] == '\n')
				s[i] = '\0';
			flag = OUT;
		}
		else if (flag == OUT)
		{
			flag = IN;
			w++;
		}
		i++;
	}
	return (w);
}
