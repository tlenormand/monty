#include "monty.h"

/**
 * op_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the address of the stack
 * Return: 0 on success, -12 or -13 on error
 */

int op_pchar(stack_t **stack)
{
	stack_t *cpy = *stack;

	if (*stack == NULL)
		return (-12);

	if (cpy->n > 0 && cpy->n < 127)
	{
		putchar(cpy->n);
		putchar('\n');
	}
	else
		return (-13);

	return (0);
}
