#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

#define IN 1
#define OUT 0

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes */

char **get_args(char *buff);
size_t wordcount(char *s);
int main(int ac, char **av, char **env);

#endif
