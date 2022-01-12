#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: pointer to the address of the stack
 * @line_number: number of the line where we are in the file
 * @number: number to add to the stack
 * Return: pointer to new stack on success, exit on error
 */

stack_t *op_push(stack_t **stack, unsigned int line_number, int number)
{
	*stack = add_dnodeint(stack, number);

	if (!stack)
	{
		fprintf(stderr, "%d", line_number);
		exit(EXIT_FAILURE);
	}

	return (*stack);
}
