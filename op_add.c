#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);
}
