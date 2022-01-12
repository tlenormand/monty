#include "monty.h"

stack_t *op_push(stack_t **stack, unsigned int line_number, int number)
{
    if (*stack == NULL)
        *stack = malloc(sizeof(stack_t));

    *stack = insert_dnodeint_at_index(stack, 0, number);

    if (!stack)
    {
        fprintf(stderr, "%d", line_number);
        exit(EXIT_FAILURE);
    }

    return (*stack);
/*
    if (node->n < 0 || node->n > 127)
    {
        fprintf(stderr, "%d", line_number);
        exit(EXIT_FAILURE);
    }

    node->n = number;
    putchar(node->n);
    putchar('\n');
*/
}
