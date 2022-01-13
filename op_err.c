#include "monty.h"

/**
 * op_err1 - function that handle opcode error
 * @err_code: id of the error
 * @l_nb: the number of the line in the file
 * @fd: file open
 * @line_buf: the line read
 * @stack: pointer to the head of stack_t
 */

void op_err1(int err_code, int l_nb, FILE *fd, char *line_buf, stack_t **stack)
{
	switch (err_code)
	{
		case -1:
			fprintf(stderr, "L%d: usage: push integer\n", l_nb);
			break;
		case -2:
			fprintf(stderr, "L%d: can't pint, stack empty\n", l_nb);
			break;
		case -3:
			fprintf(stderr, "L%d: can't pop an empty stack\n", l_nb);
			break;
		case -4:
			fprintf(stderr, "L%d: can't swap, stack too short\n", l_nb);
			break;
		case -5:
			fprintf(stderr, "L%d: can't add, stack too short\n", l_nb);
			break;
		case -6:
			fprintf(stderr, "L%d: can't sub, stack too short\n", l_nb);
			break;
		case -7:
			fprintf(stderr, "L%d: can't div, stack too short\n", l_nb);
			break;
	}

	op_err2(err_code, l_nb, fd, line_buf, stack);
}

/**
 * op_err2 - function that handle opcode error
 * @err_code: id of the error
 * @l_nb: the number of the line in the file
 * @fd: file open
 * @line_buf: the line read
 * @stack: pointer to the head of stack_t
 */

void op_err2(int err_code, int l_nb, FILE *fd, char *line_buf, stack_t **stack)
{
	switch (err_code)
	{
		case -8:
			fprintf(stderr, "L%d: division by zero\n", l_nb);
			break;
		case -9:
			fprintf(stderr, "L%d: can't mul, stack too short\n", l_nb);
			break;
		case -10:
			fprintf(stderr, "L%d: can't mod, stack too short\n", l_nb);
			break;
		case -11:
			fprintf(stderr, "L%d: division by zero\n", l_nb);
			break;
		case -12:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_nb);
			break;
		case -13:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_nb);
			break;
		case -99:
			break;
	}

	free_file(fd, line_buf, stack);

	exit(EXIT_FAILURE);
}
