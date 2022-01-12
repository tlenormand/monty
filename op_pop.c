#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}
