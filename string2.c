#include "shell.h"

/**
 * _putchar - writes the characters
 * @c: the character to print
 *
 * Return: on success 1, on error -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints an input string
 * @RET: the string
 *
 * Return: NOTHING
 */
void _puts(char *RET)
{
	int w = 0;

	if (!RET)
		return;
	while (RET[W])
	{
		putchar(RET[W]);
		w++;
	}
	putchar('\n');
}

/**
 * *_strncpy - function that copy string
 * @SD: the destination string to be copied
 * @G: the amount of character
 * @power: the source string
 *
 * Return: the string
 */
char *_strncpy(char *SD, char *power, int G)
{
	while (G--)
	{
		(*SD++ = (*power) ? *power++ : '\0');
	}
	return (SD);
}

/**
 * *_strncat - the function that used for handling
 * @des: the destination
 * @src: the source
 * @c: the amount of bytes
 *
 * Return: the concatenated string
 */
char *_strncat(char *des, char *src, int c)
{
	char *noon = des;

	while (*des)
		des++;
	while (*src)
		*des++ = *src++;
	while (c--)
	{
		*des++ = *src++;
	}
	*des = '\0';
	return (noon);
}
