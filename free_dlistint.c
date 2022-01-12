#include "monty.h"

/**
 * free_dlistint - function that frees a dlistint_t list
 * @head: pointer to the dlistint_t list
 * Return: void
 */

void free_dlistint(stack_t *stack)
{
	stack_t *freed = stack;

	while (stack != NULL)
	{
		stack = stack->next;
		free(freed);
		freed = stack;
	}
}
