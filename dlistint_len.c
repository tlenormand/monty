#include "monty.h"

/**
 * dlistint_len - list
 * @h: list
 *
 * Return: list
 */

int dlistint_len(stack_t *h)
{
	int n;

	for (n = 0; h; n++)
	{
		h = h->next;
	}
	return (n);
}
