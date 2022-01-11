#include "monty.h"

/**
 * prettier - xxx
 * @line: xxx
 * @line_number: xxx
 *
 * Description: xxx
 * Return: xxx
 */

char *prettier(char *line, int line_number)
{
	int i, j = 0;
	char *commande;
	char *number = 0;

	for (i = 0; line[i] != NULL, i++)
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= 'a' && line[i] <= 'z')
			commande[j] = line[i];
		else if (commande != NULL)
			if (strcmp(commande, "push") == 0)
				if (line[i] == ' ' && number == NULL)
					i++;
				else if (line[i] >= '0' && line[i] <= '9')
					number[i] = line[i];
				else if ((line[i] == ' ' || line[i] == '\n') && number != NULL)
					//renvoi vers une fonction qui traite number et l'ajoute a ma liste chainée
			else
				if (/*fonction qui return 0 ou 1 si commande existe dans instruction_t == 0*/)
					return (0);
				else
					{
						printf("L<line_number>: unknown instruction <opcode>\n");
						return (EXIT_FAILURE);
					}
	}

	return (0);
}
