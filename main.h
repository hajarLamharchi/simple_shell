#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <signal.h>

char *get_line();
char **parse_line(char s[]);
int create_process(char **buff, char **env);
void free_buff(char **buff);
void print_env(char **env);

#endif
