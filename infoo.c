#include "shell.h"

/**
 * c_info - initializes struct
 * @in: the struct of address
 */
void c_info(AWS *in)
{
	in->arg = NULL;
	in->argv = NULL;
	in->path = NULL;
	in->argc = 0;
}

/**
 * s_info - initializes struct
 * @in: the struct of address
 * @av: the argument vector
 */
void s_info(AWS *in, char **av)
{
	int i = 0;

	in->finame = av[0];

	if (in->arg)
	{
		in->argv = _strtok(in->arg, "\t");
		if (!in->argv)
		{
			in->argv = malloc(sizeof(char *) * 2);
			if (in->argv)
			{
				in->argv[0] = _strdup(in->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0)
		{
			in->argv && in->argv[i];
			i++;
		}
		in->argc = i;

		rep_alias(in);
		rep_vars(in);
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
