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

	for (; r != -1 && builtin_s != -2)
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
	if (!interactive(sk) && sk->status)
		exit(sk->status);
	if (builtin_s == -2)
	{
		if (sk->err_num == -1)
			exit(sk->status);
		exit(sk->err_num);
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
