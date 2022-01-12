#include "monty.h"

/**
 * find_command - function that checked if command exist
 * @command: command to execute
 * @line_number: line number of the file
 * Return: a function to the appropriate opcode
 */

int (*find_command(char *command, int line_number))(stack_t **)
{
	int i = 0;
	instruction_t instruction[] = {
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL}
	};

	while (instruction[i].opcode)
	{
		if (_strcmp(command, instruction[i].opcode) == 0)
		{
			free(command);
			return (instruction[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);

	free(command);

	return (unknow_instruction);
}
