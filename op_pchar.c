#include "monty.h"

/**
 * op_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *cpy = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (cpy->n > 0 && cpy->n < 127)
	{
		putchar(cpy->n);
		putchar('\n');
	}
}
