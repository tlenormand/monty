#include "monty.h"

/**
 * op_sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n - (*stack)->next->n;
	if (result < 0)
		result *= -1;
	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);
}
