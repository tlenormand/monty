#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

int op_swap(stack_t **stack)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-4);

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;

	return (0);
}
