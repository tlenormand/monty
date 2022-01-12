#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack
 * @stack: pointer to the address of the stack
 * Return: 0 on success, -2 on error
 */

int op_pint(stack_t **stack)
{
	if (*stack == NULL)
		return (-2);

	printf("%d\n", (*stack)->n);

	return (0);
}
