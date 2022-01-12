#include "monty.h"

/**
 * add_dnodeint_end - function that adds a new node
 * at the end of a dlistint_t list
 *
 * @head: pointer to the dlistint_t list
 * @n: value to add
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint_end(stack_t **stack, const int n)
{
	stack_t *last = *stack;
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;

		last->next = new;
		new->prev = last;
	}

	return (new);
}
