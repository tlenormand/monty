#include "monty.h"

/**
 * insert_dnodeint_at_index - function inserts a new node at a given position
 * @h: pointer to the stack_t list
 * @idx: position to insert
 * @n: value
 * Return: the address of the new node, or NULL if it failed
 */

stack_t *insert_dnodeint_at_index(stack_t **stack, unsigned int idx, int n)
{
	stack_t *new = NULL;
	stack_t *ptr = *stack;

	if (!stack)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(stack, n));

	while (idx > 0)
	{
		ptr = ptr->next;
		idx--;
		if (!ptr && idx == 0)
			return (add_dnodeint_end(stack, n));
		else if (!ptr && idx != 0)
			return (NULL);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = ptr->prev;
	new->next = ptr;

	ptr->prev->next = new;
	ptr->prev = new;

	return (new);
}
