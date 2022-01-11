#include "monty.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fd;
	int line_number = 0;
	char *line_buf;
	ssize_t line_size;
	size_t line_buf_size = 0;

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
		/* printf("line[%06d]: chars=%06ld, buf size=%06lu, contents: %s", line_number, line_size, line_buf_size, line_buf); */
		prettier(line_buf, line_number);
		line_size = getline(&line_buf, &line_buf_size, fd);
	}

	free(line_buf);
	fclose(fd);
	return (0);
}
