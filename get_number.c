#include "monty.h"

/**
 * get_number - function that get the number
 * @src: line given where get the command
 * @i: index of the line
 * Return: int containing the number
 */

int get_number(char *src, int i)
{
	int number, len = i;
	char *cpy = NULL;

	if (src == 0)
		return (-1);

	while (src[len] >= '0' && src[len] <= '9')
		len++;

	len -= i;

	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (-1);

	len = 0;

	while (src[i] >= '0' && src[i] <= '9')
	{
		*(cpy + len) = *(src + i);
		len++;
		i++;
	}

	*(cpy + len) = '\0';

	number = atoi(cpy);
	free(cpy);

	return (number);
}
