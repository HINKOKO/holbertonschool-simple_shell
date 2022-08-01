#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

#define IN 1
#define OUT 0

extern char **environ;

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **get_args(char *buff);
size_t wordcount(char *s);
int main(int ac, char **av, char **env);
void free_args(char **args);
void executor(char *buff, char **env);
char *pathfinder(char *cmd, char *PATH);
/*int executor(char **env);*/

#endif
