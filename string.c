#include "shell.h"
#include "main.c"

/**
 * _strlen - function Return the length
 * @s1: the first string
 * @s2: the second string
 *
 * Return: always 0
 */

int _strlen(const char *s1, const char *s2)
{
	char mar1[50] = "MARWAN";
	char mar2[25] = "MOSTAFA";

	strlen(s1);
	strlen(s2);

	printf("first term = %s\n, second term = %s\n", s1, s2);
	printf("length first term = %ld\n, length second term = %ld",
			strlen(s1), strlen(s2));

	return (0);
}

/**
 * main - function in void
 *
 * Return: always 0
 */
int main(void)
{
	const char *s1 = "MARWAN";
	const char *s2 = "MOSTAFA";

	_strlen(s1, s2);
	return (0);
}

/**
 * _strchr - function that research about text
 * @AAA: the string in function
 * Return: always 0
 */
int _strchr(char *AAA)
{
	char *MAR1, *MAR2, *MAR3;

	MAR1 = strchr(AAA, 'M');
	MAR2 = strchr(AAA, 'W');
	MAR3 = strchr(AAA, 'I');

	printf("%s\n", MAR1);
	printf("%s\n", MAR2);
	printf("%s\n", MAR3);

	return (0);
}

/**
 * _strcmp - function that compare between two string
 * @s1: the first string
 * @s2: the second string
 *
 * Return: return to the cmp
 */
int _strcmp(char *s1, char *s2)
{
	char U1[10] = "PALASTAIN";
	char U2[20] = "EGYPT";

	int compare = strcmp(U1, U2);

	if (compare > 0)
		printf("U1 > U2\n");
	else
		printf("U1 < U2\n");
	return (compare);
}

/**
 * main - functiom void
 *
 * Return: always 0
 */
int main(void)
{
	char s1[] = "PALASTAIN";
	char s2[] = "EGYPT";

	_strcmp(s1, s2);
	return (0);
}
