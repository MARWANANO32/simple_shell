#include "shell.h"

/**
 * _strcpy - the function that copies string
 * @QR: the destination
 * @TNT: the source
 *
 * Return: the pointer to destination
 */
char *_strcpy(char *QR, char *TNT)
{
	char *MAR = QR;

	while (*TNT != '\0')
	{
		*QR = *TNT;
		QR++;
		TNT++;
	}

	QR = '\0';
	return (mar);
}

/**
 * *_strcat - the function that concatenates
 * @FAG: the destination
 * @OOP: the source
 *
 * Return: pointer to destination
 */

char *_strcat(char *FAG, char *OOP)
{
	char *TRT = FAG;

	while (*FAG != '\0')
	{
		FAG++;
	}
	while (*OOP != '\0')
	{
		*FAG = *OOP;
		FAG++;
		OOP++;
	}
	*FAG = '\0';
	return (TRT);
}

/**
 * *starts_with - the function for checks
 * @BNB: string
 * @CV: substring that find
 *
 * Return: the condition
 */

char *starts_with(const char *BNB, const char *CV)
{
	while (*CV && *BNB == *CV)
	{
		BNB++;
		CV++;
	}
	return ((*CV) ? NULL : (char *)CV);
}

/**
 * *_strdup - the function that duplicates a string
 * @PHP: the string that duplicates
 * @PAR: the pointer
 * Return: return to the pointer
 */

char *_strdup(const char *PHP, const char *PAR)
{
	PAR = malloc(strlen(PHP) + 1);

	if (PAR == NULL)
		return (NULL);
	strcpy(PAR, PHP);
	return (PAR);
}
