#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include<sys/wait.h>

char *print_prompt();
char **parse_input(char *s);
void exec(char **buff);

#endif
