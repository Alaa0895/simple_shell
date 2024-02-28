#ifndef _SHELL_H_
#define _SHELL_H_

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

/* Macros */
#define BUFFER_SIZE 1024
#define DELIMITERS " \t\r\n\a"

/* Structs (if any) */

/* Function Prototypes */

/* Core Shell Functions */
void loop(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

/* Built-in Shell Commands Functions */
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);
int hsh_env(char **args);

/* Utility Functions */
void _printenv(void);
void signal_handler(int sig);

#endif /* _SHELL_H_ */
