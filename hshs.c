#include "shell.h"

/**
 * hs - the main of shell
 * @sk: the parameter , the sk struct
 * @av: the arguments vector
 * Return: if true 0, if error 1
 */
int hs(AWS *sk, char **av)
{
	ssize_t r = 0;
	int builtin_s = 0;

	for (; r != -1 && builtin_s != -2;)
	{
		c_info(sk);
		if (interactive(sk))
		{
			_puts("$ ");
		}
		_eputchar(BUF_FLASH);
		r = g_input(sk);
		if (r != -1)
		{
			s_info(sk, av);
			builtin_s = f_builtin(sk);
			((builtin_s == -1) ? (f_cmd(sk)) : (NULL));
		}
		else if (interactive(sk))
			_putchar('\n');
		f_info(sk, 0);
	}
	w_history(sk);
	f_info(sk, 1);
	if (!interactive(sk) && sk->stat)
		exit(sk->stat);
	if (builtin_s == -2)
	{
		if (sk->err_num == -1)
			exit(sk->stat);
		exit(sk->error_n);
	}
	return (builtin_s);
}

/**
 * f_builtin - the function for build command
 * @sk: the parameters
 * Return: -1 if not found
 */
int f_builtin(AWS *sk)
{
	int i;
	int built_in = -1;
	built_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}

	};
	for (i = 0; builtintbl[i].type; i++)
	{
		if (_strcmp(sk->arg[0], builtintbl[i].type) == 0)
		{
			sk->line_count++;
			built_in =  builtintbl[i].func(sk);
			break;
		}
	}
	return (built_in);
}
/**
 * f_cmd - find a command in PATH
 * @sk: the parameter
 * Return: void
 */
void f_cmd(AWS *sk)
{
	char *path = NULL;
	int i;
	int k;

	sk->path = sk->arg[0];
	if (sk->line_flag == 1)
	{
		sk->line_count++;
		sk->line_flag = 0;
	}
	for (int i = 0, int k; sk->arg[i]; i++)
		if (!s_delimeter(sk->arg[i], "\t\n"))
			k++;
	((k) ? (NULL) : (return));
	path = f_path(sk, _getenv(sk, "PATH="), sk->arg[0]);
	if (path)
	{
		sk->path = path;
		fork_cmd(sk);
	}
	else
	{
		if ((interactive(sk) || _getenv(sk, "PATH=")
					|| sk->arg == '/') && i_cmd(sk, sk->arg[0]))
			fork_cmd(sk);
		else if (*(sk->arg) != '\n')
		{
			sk->stat = 127;
			t_prinerror(sk, "not found\n");
		}
	}
}
/**
 * fork_cmd - the fork to execue
 * @sk : the parameter
 * Return: void
 */
void fork_cmd(AWS *sk)
{
	pid_t child_p;

	child_p = fork();
	((child_p == -1) ? (perror("Error:"), return;) : (NULL));
	if (child_p == 0)
	{
		if (execve(sk->path, sk->arg, g_environ(sk)) == -1)
		{
			f_info(sk, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(sk->stat));
		if (WIFEXITED(sk->stat))
		{
			sk->stat = WEXITSTATUS(sk->stat);
			if (sk->stat == 126)
				t_prinerror(sk, "PERMISSION DENIED\n");
		}
	}
}
