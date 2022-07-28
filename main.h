#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

char **get_args(char *buff);
size_t wordcount(char *s);
int main(int ac, char **av, char **env);

#endif
