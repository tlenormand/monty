#include "monty.h"

/**
 * prettier - xxx
 * @line: xxx
 * @line_number: xxx
 *
 * Description: xxx
 * Return: xxx
 */

int prettier(char *line, int line_number)
{
	int i, j = 0;
	char *commande;
	char *number = 0;

	commande = malloc(sizeof(char) * strlen(line));
	number = malloc(sizeof(char) * strlen(line));

	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
		{
			j = 0;
		}
		else if (line[i] >= 'a' && line[i] <= 'z')
		{
			commande[j] = line[i];
			j++;
		}
		else if (commande != NULL)
		{
			if (strcmp(commande, "push") == 0)
			{
				if (line[i] == ' ' && number == 0)
				{
					continue;
				}
				else if (line[i] >= '0' && line[i] <= '9')
				{
					number[i] = line[i];
				}
				else if ((line[i] == ' ' || line[i] == '\n') && number != NULL)
				{ /* renvoi vers une fonction qui traite number et l'ajoute a ma liste chainée */
					printf("to do3\n");
					return (0);
				}
			}
			else
			{
				if (/* fonction qui return 0 ou 1 si commande existe dans instruction_t == 0 */ i == 0)
				{
					return (0);
				}
				else
				{
					printf("L%d: unknown instruction %s\n", line_number, commande);
					return (EXIT_FAILURE);
				}
			}
		}
	}
	free(number);
	free(commande);

	return (0);
}
