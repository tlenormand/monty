#include "monty.h"

void push(stack_t **stack, unsigned int line_number, FILE *fd);

/**
 * @brief 
 * 
 * @param stack 
 * @param line_number 
 * @param fd 
 */

void push(stack_t **stack, unsigned int line_number, FILE *fd)
{
	stack_t *node = *stack;

	if (!node)
	{
		fprintf(fd, "%d", line_number);
		free(line_number);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		fprintf(fd, "%d", line_number);
		free(line_number);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * @brief 
 * 
 * @param stack 
 * @param line_number 
 */

void pall(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if (!*stack)
			return (0);
		while (*stack)
		{
			printf("%d\n", *stack->n);
			*stack = *stack->next;
			nodes++;
		}
	}
}
