#include "monty.h"

/**
 * delete_dnodeint_at_index - function that delete
 * the node at index "index" of a stack_t linked list
 *
 * @stack: pointer to the stack_t list
 * @index: position to indexete
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(stack_t **stack, unsigned int index)
{
	stack_t *del = *stack;

	if (*stack == NULL)
		return (-1);

	if (index == 0)
		*stack = (*stack)->next;
	else
	{
		while (index > 0)
		{

			del = del->next;
			index--;
			if (del == NULL)
				return (-1);
		}
	}

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	free(del);

	return (1);
}
