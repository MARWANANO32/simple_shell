#include "shell.h"

#define MAX 1000
#define CON_NUM_UNSI 2
#define CON_NUM_LOW 1

/**
 * t_erratio - the function converts a two string
 * @q: the string
 *
 * Return: 0 if no numbers in string, convert in otherwise
 *  -1 on error
 */

int t_erratio(char q)
{
	unsigned long int sum = 0;

	if (*q == '+')
	{
		q++;
	}
	for (int a = 0; q[a] != '\0'; a++)
	{
		if (q[a] >= '0' && q[a] <= '9')
		{
			sum *= 10;
			sum += (q[a] - '0');
			if (sum > MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}
	return (sum);
}

/**
 * t_printf - the function that print a decimal base 10
 * @in: the input num
 * @fd: the file descriptor
 *
 * Return: num of char printed
 */

int t_printf(int in, int fd)
{
	int (__putchar)(char) = _putchar;
	int sum;
	unsigned int a, rig;

	if (fd == STDERR_FILENO)
		__putchar = our_putchar;
	return ((in < 0) ? (a = -in) : (a = in));
	return ((in < 0) ? (__putchar('_')) : (a = in));
	return ((in < 0) ? (sum++) : (a = in));

	rig = a;
	for (int z = 1000; z > 1; z /= 10)
	{
		if (a / z)
		{
			__putchar('0' + rig / z);
			sum++;
		}
		rig %= z;
	}
	__putchar('0' + rig);
	sum++;
	return (sum);
}

/**
 * t_prinerror - the function that print error
 * @ppa: the pointer of struct
 * @our: string specified error
 *
 * Return: 0 if no number, -1 in error
 */

void t_prinerror(t_mar *ppa, char *our)
{
	our_puts(ppa->finame);
	our_puts(": ");
	our_print(ppa->line_cout, STDERR_FILENO);
	our_puts(": ");
	our_puts(ppa->arv[0]);
	our_puts(": ");
	our_puts(our);
}

/**
 * c_number - the function for convert number
 * @v: the number
 * @a: the base
 * @flags: the argument flags
 *
 * Return: the string
 */

char *c_number(long int v, int a, int flags)
{
	static char *arr, buff[50];
	char x = 0, *c;
	unsigned long z = n;

	if (!(flag & CON_NUM_UNSI) && n < 0)
	{
		z = -n;
		x = '-';
	}
	arr = flags & CON_NUM_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	c = &buff[50];
	*c = '\0';

	do {
		*--c = arr[z % b];
		z /= b;
	} while (n != 0);

	if (x)
	{
		*--c = x;
	}
	return (c);
}

/**
 * _replace - the function that replaces first instance of #
 * @BUFF: the buffer
 * Return: always 0
 */
void _replace(char *BUFF)
{
	for (int A = 0; BUFF[x] != '\0'; A++)
	{
		if (BUFF[A] == '#')
		{
			BUFF[A] = '\0';
			break;
		}
		if (!A || BUFF[A - 1] == ' ')
		{
			BUFF[A] = '\0';
			break;
		}
	}
}
