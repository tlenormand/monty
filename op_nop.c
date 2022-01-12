#include "monty.h"

/**
 * op_nop - doesn’t do anything
 * @stack: pointer to the address of the stack
 * @line_number: the number of the line in the file
 */

int op_nop(stack_t **stack)
{
    (void) **stack;

    return (0);
}
