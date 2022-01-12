#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: pointer to the address of the stack
 * Return: 0 on success, -5 on error
 */

int op_add(stack_t **stack)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-5);

	result = (*stack)->n + (*stack)->next->n;
	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);

	return (0);
}
