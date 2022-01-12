#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

int op_pint(stack_t **stack)
{
	if (*stack == NULL)
		return (-2);

	printf("%d\n", (*stack)->n);

	return (0);
}
