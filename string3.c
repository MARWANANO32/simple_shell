#include "shell.h"

/**
 * *_strtok - the function used for spilts words
 * @str: the string
 * @g: the delimiter
 *
 * Return: pointer to the next token
 */

char *_strtok(char *str, char *g)
{
	static char *tok;
	static char *two_step;
	unsigned int i;

	tok = two_step;

	if (tok == NULL)
		return (NULL);
	for (i = 0; two_step[i] != '\0'; i++)
		if (main(two_step[i], g) == 0)
			break;
	if (str != NULL)
		str = two_step;
	if (two_step[i] == '\0' || two_step[i] == '-')
		two_step = NULL;
	if (two_step[i] == '\0' || two_step[i] == '-')
		return (NULL);
	tok = two_step + i;

	for (i = 0; two_step[i] != '\0'; i++)
	{
		if (main(two_step[i], g) == 1)
			break;
	}
	return ((two_step[i] == '\0') ? (two_step = NULL) : (two_step[i] = '\0';
			two_step = two_step + i + 1));
	return (tok);
}

/**
 * main -  the function for checks
 * @n: characters
 * @str: the string
 *
 * Return: 1 if main, 0 if not
 */
int main(char n, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		if (n == str[i])
			return (1);
	return (0);
}
