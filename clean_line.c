#include "monty.h"

/**
 * clean_line - translate all '\n' '\t' and '#' into ' ' or '\0'
 * @line: pointer to the line
 * Return: the line clean
 */

char *clean_line(char *line)
{
	int i;

	for (i = 0; line[i]; i++) /*convert tab to space*/
	{
		if (line[i] == 9)
			line[i] = ' ';
		if (line[i] == '#' || line[i] == '\n')
			line[i] = '\0';
	}

	return (line);
}
