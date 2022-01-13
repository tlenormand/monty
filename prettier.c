#include "monty.h"

/**
 * prettier - function that check if the line is an opcode
 * @line: line to control
 * @line_number: the number of the line in the file
 * @command: pointer to the opcode command
 * @stack: pointer to the head of stack_t
 *
 * Description: first, get the command. If it is a push then push and return
 * else checked if the command exist and execute the function pointed
 * Return: 0 on success, else otherwise
 */

int prettier(char *line, int line_number, char **command, stack_t **stack)
{
	int i, number;

	for (i = 0; line[i]; i++) /*convert tab to space*/
	{
		if (line[i] == 9)
			line[i] = ' ';
		if (line[i] == '#' || line[i] == '\n')
			line[i] = '\0';
	}
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
			continue;
		else if (line[i] != ' ') /*get the command*/
		{
			*command = get_command(line, i);
			while (line[i] != ' ' && line[i])
				i++;
			if (*command) /*if command exist*/
			{
				if (_strcmp(*command, "push") == 0) /*if command is push*/
				{
					free(*command);
					while (line[i] == ' ' && line[i])
						i++;
					if (line[i] == '\n' || line[i] == '\0')
						return (-1);
					number = get_number(line, i);
					if (number == -123456)
						return (-1);
					*stack = op_push(stack, line_number, number);
					return (0);
				}
				else
					return (find_command(*command, line_number)(stack));
			}
		}
	}

	return (0);
}
