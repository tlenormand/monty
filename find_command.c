#include "monty.h"

/**
 * find_command - function that checked if command exist
 * @command: command to execute
 * @line_number: line number of the file
 * Return: a function to the appropriate opcode
 */

void (*find_command(char *command, int line_number))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instruction[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	while (instruction[i].opcode)
	{
		if (_strcmp(command, instruction[i].opcode) == 0)
			return (instruction[i].f);
		i++;
	}

	printf("L%d: unknown instruction %s\n", line_number, command);

	free(command);
	exit(EXIT_FAILURE);
}
