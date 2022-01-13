#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @stack: pointer to the address of the stack
 * Return: 0 on success, -3 on error
 */

int op_pop(stack_t **stack)
{
	if (*stack == NULL)
		return (-3);

	delete_dnodeint_at_index(stack, 0);

	return (0);
}
