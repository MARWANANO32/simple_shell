#ifndef SHELL_H
#define SHELL_H

/**THE LIBRARYIES STANDARD**/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>
#include <limits.h>

#define BUFFER 1000
#define INFO_INIT
{NULL, NULL, NULL, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL,
	0, 0, 0, 0}

extern char **environ;

/**
 * struct AWS - contain pseudo-arguments to pass into a function
 *       allowing uniform prototype for function
 * @arg: a string contains a argument form getline
 * @arv: the array of the string
 * @path: the path of string
 * @finame: the file name
 * @env: the linked list
 * @cmd_buffer: the address of pointer
 * @arc: the arguments for count
 * @num: the number of bytes for exit function
 * @line_count: the error for count line
 * @error_n: the error of code for exit()
 * @line_flag: the input of the line
 * @env_chang: the modified copy of env
 * @stat: the function for last exected command
 * @cmd_type: the sympols ||, &&, ;
 * @hist_count: the history line of number
 * @readfi: the file descriptor for read
 * @history: the history of node
 * @alias: the alias of node
 */
typedef struct AWS
{
	char *arg;
	char **arv;
	char *path;
	char *finame;
	char **env;
	char **cmd_buffer;
	int arc;
	int num;
	unsigned int line_count;
	int error_n;
	int line_flag;
	int env_chang;
	int stat;
	int cmd_type; /* pointer to cmd */
	int hist_count;
	int readfi;
	list *history;
	list alias;
} AWS;

/**
 * struct OPPS - the singly linked list
 * @a: the number of fields
 * @str: the string of function
 * @next: the pointer for next node
 */
typedef struct OPPS
{
	int a;
	char *str;
	struct OPPS *next;
} OPPS_t;

/***string.c***/
int _strlen(const char *, const char *);
int _strchr(char *);
int _strcmp(char *, char *);


/***string1.c***/
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *starts_with(const char *, const char *);
char *_strdup(const char *, const char *);

/***string2.c***/
int _putchar(char c);
void _puts(char *);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);

/***string3.c***/
char *_strtok(char *, const char *);
int main(char, const char *);

/***memory.c***/
char *s_memset(char *, char, unsigned int);
void sfree(char **);
void *s_realloc(void *, unsigned int, unsigned int);

/***memory1.c***/
int _sfree(int **);

/***check.c***/
int interactive(mar_t *valid);
int s_delimeter(char s, char *delimeter);
int t_isalphatic(int c);
int u_atio(char *mar);

/***err.c***/
void _replace(char *BUFF);
char *c_number(long int v, int a, int flags);
void t_prinerror(t_mar *ppa, char *our);
int t_printf(int in, int fd);
int t_erratio(char q);

/***list_string.c***/
OPPS_t *added_node(OPPS_t **header, const char *str, int n);
OPPS_t *added_end_node(OPPS_t **header, const char *str, int n);
size_t prints_list(const OPPS_t *a);
int deleted_node(OPPS_t **header, unsigned int end);
void free_lists(OPPS_t **header_str);

/***list_string1.c***/

#endif
