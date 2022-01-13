#include "monty.h"

/**
 * op_pall - prints all the values on the stack
 * starting from the top of the stack
 * @stack: pointer to the address of the stack
 * Return: 0
 */

int op_pall(stack_t **stack)
{
	stack_t *cpy = *stack;

	if (cpy)
	{
		while (cpy)
		{
			printf("%d\n", cpy->n);
			cpy = cpy->next;
		}
	}

	return (0);
}
