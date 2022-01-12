#include "monty.h"

/**
 * free_file - function that free all memory allocated
 * @fd: file open
 * @line_buf: the line read
 */

void free_file(FILE *fd, char *line_buf)
{
	(void) line_buf;

	if (stack)
		free_dlistint(stack);

	fclose(fd);
}
