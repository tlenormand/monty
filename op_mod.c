#include "monty.h"

/**
 * op_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		result = (*stack)->n % (*stack)->next->n;
	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);
}
