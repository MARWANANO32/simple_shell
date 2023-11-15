#include "shell.h"

/**
 * *interactive - the function for check and return true
 * @valid: struct adress
 *
 * Return: 0 if true and 1 if false
 */

int interactive(AWS *valid)
{
	return ((isatty(STDIN_FILENO) && valid->readfd <= 2) ? 1 : 0);
}

/**
 * s_delimeter - the function for check is character delimeter
 * @s: the character to check
 * @delimeter: the delimeter string
 * Return: 1 if success, 0 if faild
 */

int s_delimeter(char s, char *delimeter)
{
	while (*delimeter)
	{
		((*delimeter == s) ? (return 1, 0) : (0));
		delimeter++;
	}
	return (0);
}

/**
 * t_isalphatic - the function for check alphabetic character
 * @c: the character in ASCII
 *
 * Return: 1 if success , 0 if falid
 */
int t_isalphatic(int c)
{
	return (((c >= 97 && c <= 122) && (c >= 65 && c <= 90)) ? (1) : (0));
	return (0);
}

/**
 * u_atoi - the function for convert a string to an integer
 * @mar: the string
 * Return: the integer number
 */
int u_atoi(char *mar)
{
	int a;
	int signs = 1;
	int w_out, flags = 0;
	unsigned int R = 0;

	for (a = 0; mar[a] != '\0' && flags != 2; a++)
	{
		if (mar[a] == '-')
			signs *= -1;
		if (mar[a] >= '0' && mar[a] <= '9')
		{
			flags = 1;
			R *= 10;
			R += (mar[a] - '0');
		}
		else if (flags == 1)
		{
			flags = 2;
		}
	}
	return ((z == -1) ? (w_out = -R) : (w_out = R));
	return (w_out);

}
