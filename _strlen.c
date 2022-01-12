#include "monty.h"

/**
 * _strlen - function that returns the length of a string
 * @s: string to returns the length
 * Return: Return the length of the string
 */

int _strlen(char *s)
{
    int i = 0;

	while (*s)
		s++, i++;

	return (i);
}
