#include "monty.h"

/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the address of the stack
 * Return: 0
 */

int op_pstr(stack_t **stack)
{
	stack_t *cpy = *stack;

	while (cpy->n)
	{
		putchar(cpy->n);
		cpy = cpy->next;
	}

	putchar('\n');

	return (0);
}
