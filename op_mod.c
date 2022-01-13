#include "monty.h"

/**
 * op_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to the address of the stack
 * Return: 0 on success, -10 or -12 on error
 */

int op_mod(stack_t **stack)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-10);

	if ((*stack)->n == 0)
		return (-11);

	result = (*stack)->next->n % (*stack)->n;

	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);

	return (0);
}
