#include "monty.h"

/**
 * get_command - function that get the commmand
 * @src: line given where get the command
 * @i: index of the line
 * Return: string containing the command, NULL if failled
 */

char *get_command(char *src, int i)
{
	int len = i;
	char *cpy = NULL;

	if (src == 0)
		return (NULL);

	while ((src[len] != ' ' && src[len] != '\n') && src[len])
		len++;

	len -= i;

	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);

	len = 0;

	while ((src[i] != ' ' && src[i] != '\n') && src[i])
	{
		*(cpy + len) = *(src + i);
		printf("src de i : %c\n", src[i]);
		len++;
		i++;
	}

	*(cpy + len) = '\0';

	return (cpy);
}
