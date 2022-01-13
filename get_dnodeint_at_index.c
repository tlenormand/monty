#include "monty.h"

/**
 * get_dnodeint_at_index - function that adds a new node
 * at the beginning of a stack_t list
 *
 * @head: pointer to the stack_t list
 * @n: value to add
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *get_dnodeint_at_index(stack_t *stack, const int index)
{
	int n = 0;

	while (stack && n < index)
	{
		stack = stack->next;
		n++;
	}
	return (stack);
}
