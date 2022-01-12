#include "monty.h"

/**
 * op_div - prints all the values on the stack
 * starting from the top of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack)
	{
		while (*stack)
		{
			printf("%d\n", (*stack)->n);
			(*stack) = (*stack)->next;
		}
	}
}
