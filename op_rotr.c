#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *cpy = *stack;
	int end = dlistint_len(*stack);
	int result = 0;

	(void)line_number;

	if (*stack)
	{
		cpy = get_dnodeint_at_index(*stack, end - 1);
		result = cpy->n;
		delete_dnodeint_at_index(stack, end - 1);
		add_dnodeint(stack, result);
	}
	else
		return;
}
