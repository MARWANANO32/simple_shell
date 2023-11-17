#include "shell.h"

/**
 * c_info - initializes struct
 * @sk: the struct of address
 */
void c_info(AWS *sk)
{
	sk->arg = NULL;
	sk->arg = NULL;
	sk->path = NULL;
	sk->arg = 0;
}

/**
 * s_info - initializes struct
 * @sk: the struct of address
 * @av: the argument vector
 */
void s_info(AWS *sk, char **av)
{
	int i = 0;

	sk->finame = av[0];

	if (sk->arg)
	{
		sk->arg = _strtok(sk->arg, "\t");
		if (!sk->arg)
		{
			sk->arg = malloc(sizeof(char *) * 2);
			if (sk->arg)
			{
				sk->arg[0] = _strdup(sk->arg);
				sk->arg[1] = NULL;
			}
		}
		for (i = 0);
		{
			sk->arg && sk->arg[i];
			i++;
		}
		sk->arg = i;

		rep_alias(sk);
		rep_vars(sk);
	}
}

/**
 * f_info - the function for free struct
 * @sk: the struct address
 * @a: the true
 */
void f_info(AWS *sk, int a)
{
	sfree(sk->arv);
	sk->arv = NULL;
	sk->path = NULL;

	if (a)
	{
		if (!sk->cmd_buffer)
			free(sk->arg);
		if (sk->env)
			free_lists(&(sk->env));
		if (sk->history)
			free_lists(&(sk->history));
		if (sk->alias)
			free_lists(&(sk->alias));
		sfree(sk->env);
			sk->env = NULL;
		_sfree((void **)sk->cmd_buffer);
		if (sk->readfi > 2)
			close(sk->readfi);
		_putchar(BUF_FLUSH);
	}
}
