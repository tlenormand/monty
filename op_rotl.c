#include "monty.h"

/**
 * op_rotl - rotates the stack to the top
 * @stack: pointer to the address of the stack
 * Return: 0
 */

int op_rotl(stack_t **stack)
{
	stack_t *cpy = *stack;
	int end = dlistint_len(*stack);
	int result = 0;

	if (*stack)
	{
		cpy = get_dnodeint_at_index(*stack, end - 1);
		result = cpy->n;
		delete_dnodeint_at_index(stack, end - 1);
		add_dnodeint(stack, result);
	}

	return (0);
}
