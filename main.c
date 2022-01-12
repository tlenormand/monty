#include "monty.h"

/**
 * main - interperet a monty file (.m)
 * @argc: number of arguments
 * @argv: value of arguments
 * Return: 0 always
 */

int main(int argc, char **argv)
{
	FILE *fd;
	unsigned int line_number = 0;
	char line_buf[1024];
	char *line, *command;
	int prettier_return, space = 0, size = 1024;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = fgets(line_buf, size, fd);
	while (line != NULL)
	{
		line_number++;

		space = 0;
		while (line_buf[space] == ' ')
			space++;

		if (line_buf[space] != '\n')
		{
			prettier_return = prettier(line_buf, line_number, &command);
			if (prettier_return < 0)
				op_err1(prettier_return, line_number, fd, line_buf);
		}
		line = fgets(line_buf, size, fd);
	}

	free_file(fd, line_buf);

	return (0);
}
