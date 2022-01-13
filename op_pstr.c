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
	{
		putchar('\n');
		return (0);
	}

	while ((cpy->n > 0 && cpy->n < 127 && cpy) || !*stack)
	{
		putchar(cpy->n);
		if (!cpy->next)
			break;
		cpy = cpy->next;
	}

	putchar('\n');

	return (0);
}
