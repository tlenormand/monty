#include "monty.h"

/**
 * free_file - function that free all memory allocated
 * @fd: file open
 * @line_buf: the line read
 * @stack: pointer to the head of stack_t
 */

void free_file(FILE *fd, char *line_buf, stack_t **stack)
{
	(void) line_buf;

	if (stack)
		free_dlistint(stack);

	fclose(fd);
}
