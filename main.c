#include "monty.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fd;
	unsigned int line_number = 0;
	char *line_buf = NULL;
	ssize_t line_size = 0;
	size_t line_buf_size = 0;
	char *command;
	int prettier_return;

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

	line_size = getline(&line_buf, &line_buf_size, fd);
	while (line_size != -1)
	{
		line_number++;
		if (line_buf[0] != '\n')
		{
			prettier_return = prettier(line_buf, line_number, &command);
			/* if error in opcode */
			if (prettier_return < 0)
				op_err(prettier_return, line_number, fd, line_buf, command);
			if (command)
				free(command);
		}
		/* next line */
		line_size = getline(&line_buf, &line_buf_size, fd);
	}

	free_file(fd, line_buf, command);

	return (0);
}
