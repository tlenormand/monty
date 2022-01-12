#include "monty.h"

/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cpy = *stack;

	if (*stack == NULL && cpy->n < 0 && cpy->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (cpy->n)
	{
		putchar(cpy->n);
		cpy = cpy->next;
	}
	putchar('\n');
}
