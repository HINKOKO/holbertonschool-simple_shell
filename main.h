#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

#define IN 1
#define OUT 0

extern char **environ;

typedef struct built_in
{
	char *command;
	int (*f)(char *cmd, char **args, char **env);
} built_in;

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **get_args(char *buff);
size_t wordcount(char *s);
void free_args(char **args);
int executor(char *buff, char **env);
char *pathfinder(char *cmd, char *PATH);
int new_exit(char *cmd, char **args, char **env);
int (*check_builtin(char *command))(char *cmd, char **args, char **env);
int exec_path(char **args, char **env);

#endif
