#include "monty.h"

/**
 * op_err - function that handle opcode error
 * @err_code: id of the error
 * @line_number: the number of the line in the file
 * @fd: file open
 * @line_buf: the line read
 */

void op_err(int err_code, int line_number, FILE *fd, char *line_buf, char *command)
{
	switch (err_code)
	{
		case -1:
			fprintf(stderr, "L%d: usage: push integer", line_number);
			break;
		case -2:
			fprintf(stderr, "L%d: can't pint, stack empty", line_number);
			break;
		case -3:
			fprintf(stderr, "L%d: can't pop an empty stack", line_number);
			break;
		case -4:
			fprintf(stderr, "L%d: can't swap, stack too short", line_number);
			break;
		case -5:
			fprintf(stderr, "L%d: can't add, stack too short", line_number);
			break;
		case -6:
			fprintf(stderr, "L%d: can't sub, stack too short", line_number);
			break;
		case -7:
			fprintf(stderr, "L%d: can't div, stack too short", line_number);
			break;
		case -8:
			fprintf(stderr, "L%d: division by zero", line_number);
			break;
		case -9:
			fprintf(stderr, "L%d: can't mul, stack too short", line_number);
			break;
		case -10:
			fprintf(stderr, "L%d: can't mod, stack too short", line_number);
			break;
		case -11:
			fprintf(stderr, "L%d: division by zero", line_number);
			break;
		case -12:
			fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
			break;
		case -13:
			fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
			break;
	}

	free_file(fd, line_buf, command);

	exit(EXIT_FAILURE);
}
