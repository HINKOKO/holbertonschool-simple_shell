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
#include <signal.h>

/* Program Running commands */

void _prompt(void);
int executor(char *buff, char **env, int line);
int exec_path(char **args, char **env, int line);
char *pathfinder(char *cmd, char *PATH);

/* Builtin helpers functions */

int (*check_builtin(char *command))(char *cmd, char **args, char **env);
int new_exit(char *cmd, char **args, char **env);

/* Strings functions */

char **get_args(char *buff);
size_t wordcount(char *s);
void free_args(char **args);

/* Env functions */

int print_env(char *cmd, char **args, char **env);
void handle_signal(__attribute__((unused)) int signum);

#endif
