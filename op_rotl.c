#include "monty.h"

/**
 * op_rotl - rotates the stack to the top
 * @stack: pointer to the address of the stack
 * Return: 0
 */

int op_rotl(stack_t **stack)
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
	else
		return (0);
}
