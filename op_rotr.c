#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom
 * @stack: pointer to the address of the stack
 * Return: 0
 */

int op_rotr(stack_t **stack)
{
	stack_t *cpy = *stack;
	int result;

	if (*stack)
	{
		cpy = get_dnodeint_at_index(*stack, 0);
		result = cpy->n;
		delete_dnodeint_at_index(stack, 0);
		add_dnodeint_end(stack, result);
	}

	return (0);
}
