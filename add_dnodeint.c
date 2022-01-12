#include "monty.h"

/**
 * add_dnodeint - function that adds a new node
 * at the beginning of a stack_t list
 *
 * @stack: pointer to the stack_t list
 * @n: value to add
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = (*stack);
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;

	(*stack) = new;

	return (new);
}
