#include "monty.h"

/**
 * prettier - function that check if the line is an opcode
 * @line: line to control
 * @line_number: the number of the line in the file
 * @command: pointer to the opcode command
 *
 * Description: first, get the command. If it is a push then push and return
 * else checked if the command exist and execute the function pointed
 * Return: 0 on success, else otherwise
 */

int prettier(char *line, int line_number, char **command)
{
	int i, number;
	stack_t **stack = malloc(sizeof(stack_t) * 10);

	for (i = 0; line[i]; i++)
	{
		/*skip spaces*/
		if (line[i] == ' ')
			continue;

		/*get the command*/
		else if (line[i] >= 'a' && line[i] <= 'z')
		{
			*command = get_command(line, i);

			while (line[i] != ' ')
				i++;

			/*if command exist*/
			if (*command != NULL)
			{
				/*if command is push*/
				if (_strcmp(*command, "push") == 0)
				{
					while (line[i] == ' ')
						i++;
					/*Attention, comment savoir si c'est OK, si on a bien un nombre en retour
					genre si on tombe sur un strin, il faut faire un exit dans get_number que je n'ai pas fait*/
					/*attention si nombre négatif ? --> y a t il des nombres négatifs */
					number = get_number(line, i);
					printf("number : %d\n",number);
					/* renvoi vers une fonction qui traite number et l'ajoute a ma liste chainée */
					printf("to do3\n");
					return (0);
				}
				else
				{
					find_command(*command, line_number)(stack, line_number);
					return (0);
				}
			}
		}
	}

	return (0);
}
