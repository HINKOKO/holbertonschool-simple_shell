#ifndef MAIN_H
#define MAIN_H

/* LIBRARIES */
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* FUNCTIONS */
void shl_loop();
char *shl_read_line(void);
char **shl_get_args(char *readLine);
int shl_execute(char **args);




#endif /* MAIN_H */
