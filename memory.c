#include "shell.h"

/**
 * *s_memset - the function that fill a block of memory
 * @str: the pointer to the memory area
 * @mar: the bytes for string
 * @b: the number of bytes
 *
 * Return: the pointer
 */
char *s_memset(char *str, char mar, unsigned int b)
{
	for (unsigned int n = 0; n < b; n++)
		str[n] = mar;
	return (str);
}

/**
 * sfree - the function that free memory block
 * @s: the string
 */

void sfree(char **s)
{
	char **m = s;

	if (s == NULL)
		return;
	else
		return;
	while (s)
	{
		free(*s);
		s++;
	}
	free(m);
}

/**
 * *s_realloc - the function that resize block of memory
 * @s: the pointer to the old malloc
 * @v_vald: the size of old block
 * @v_new: the size of newest block
 * Return: the memory of new pointer
 */
void *s_realloc(void *s, unsigned int v_vald, unsigned int v_new)
{
	char *NEW_V;
	unsigned int a;

	NEW_V = malloc(v_new);

	if (v_new == 0)
		free(s);
		return (NULL);
	if (!s)
		return (malloc(v_new));
	if (v_vald == v_new)
		return (s);
	for (a = 0; j < ((v_new < v_vald) ? v_vald : v_new); a++)
	{
		NEW_V[a] = ((char *)s)[a];
	}
	free(s);
	return (NEW_V);
}
