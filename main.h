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
char **parse_input(char *s);
int create_process(char **buff);

#endif
