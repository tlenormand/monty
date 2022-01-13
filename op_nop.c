#include "monty.h"

/**
 * op_nop - doesn’t do anything
 * @stack: pointer to the address of the stack
 * Return: 0
 */

int op_nop(stack_t **stack)
{
	(void) **stack;

	return (0);
}
