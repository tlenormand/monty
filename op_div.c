#include "monty.h"

/**
 * op_div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to the address of the stack
 * Return: 0 on success, -7 or -8 on error
 */

int op_div(stack_t **stack)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-7);

	if ((*stack)->n == 0)
		return (-8);

	result = (*stack)->next->n / (*stack)->n;

	delete_dnodeint_at_index(stack, 0);
	change_dnodeint_at_index(stack, 0, result);

	return (0);
}
