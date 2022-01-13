#include "monty.h"

/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the address of the stack
 * Return: 0
 */

int op_pstr(stack_t **stack)
{
	stack_t *cpy = *stack;

	if (!*stack)
		return (-12);

	while (cpy->n > 0 && cpy->n < 127 && cpy)
	{
		putchar(cpy->n);
		if (!cpy->next)
			break;
		cpy = cpy->next;
	}
	if (cpy->n < 0 || cpy->n > 127)
		return (-13);

	putchar('\n');

	return (0);
}
