#include "shell.h"

/**
 * _sfree - the function that free a pointer and nulls
 * @address: address of the pointer to free
 *
 * Return: 1 if free, otherwise 0
 */

int _sfree(int **address)
{
	if (address)
	{
		free(*address);
		*address = NULL;
		return (1);
	}
	if (*address)
	{
		free(*address);
		*address = NULL;
		return (1);
	}
	return (0);
}
