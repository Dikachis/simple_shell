#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

#define _NORMAL 1
#define _SKIP 2
#define _SHELL_END 3

void _env(char **com);
int promptshell();
int promptshell(void);
char **getToken(char **buf, char *pattern);
void shellInstance(void);
void execute(char *arg, char **args);

#endif /* _SHELL_H_ */
