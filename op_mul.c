#include "monty.h"

/**
 * op_mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->n) * ((*stack)->next->n);
	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);
}
