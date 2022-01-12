#include "monty.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fd;
	unsigned int line_number = 0;
	char line_buf[1024];
	char *line_size;
	int line_buf_size = 1024;
	char *command;
	int prettier_return;
	int space = 0;

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

	line_size = fgets(line_buf, line_buf_size, fd);
	while (line_size != NULL)
	{
		line_number++;

		space = 0;
		while (line_buf[space] == ' ')
			space++;

		if (line_buf[space] != '\n')
		{
			prettier_return = prettier(line_buf, line_number, &command);
			/* if error in opcode */
			if (prettier_return < 0)
				op_err(prettier_return, line_number, fd, line_buf);
		}
		/* next line */
		line_size = fgets(line_buf, line_buf_size, fd);
	}

	free_file(fd, line_buf);

	return (0);
}
