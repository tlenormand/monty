#include "monty.h"

/**
 * change_dnodeint_at_index - function that change
 * the value of a node at index "index" of a stack_t linked list
 *
 * @stack: pointer to the stack_t list
 * @index: position to indexete
 * @value: new value to put
 * Return: 1 if it succeeded, -1 if it failed
 */

int change_dnodeint_at_index(stack_t **stack, unsigned int index, int value)
{
	if (*stack == NULL)
		return (-1);

	while (index > 0)
	{
		*stack = (*stack)->next;
		index--;
		if (*stack == NULL)
			return (-1);
	}

	(*stack)->n = value;

	return (1);
}
