#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

#define IN 1
#define OUT 0

char **get_args(char *buff);
size_t wordcount(char *s);
int main(int ac, char **av, char **env);

#endif
