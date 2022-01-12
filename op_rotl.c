#include "monty.h"

/**
 * op_rotl - rotates the stack to the top
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *cpy = *stack;
	int result;

	(void)line_number;

	if (*stack)
	{
		cpy = get_dnodeint_at_index(*stack, 0);
		result = cpy->n;
		delete_dnodeint_at_index(stack, 0);
		add_dnodeint_end(stack, result);
	}
	else
		return;
}
