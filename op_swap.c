#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
