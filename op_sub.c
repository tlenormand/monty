#include "monty.h"

/**
 * op_sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

int op_sub(stack_t **stack)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-6);

	result = (*stack)->n - (*stack)->next->n;
	if (result < 0)
		result *= -1;

	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);

	return (0);
}
