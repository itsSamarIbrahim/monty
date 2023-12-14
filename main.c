#include "monty.h"

instruction_t opcodes[NUM_OP_CODES] = {
    {"push", push},
    {"pall", pall}
};

/**
 *
 */
int main(int ac, char **av)
{
	char *file_name, *line, *opcode;
	FILE *file;
	size_t line_size;
	unsigned int line_num;
	stack_t *stack;
	int a, op_code_found, cmp_result;
	/* ssize_t text; */

	if (ac != 2 || av[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_name = av[1];
	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	/* buffer */
	line = NULL;
	/* buffer size */
	line_size = 0;
	line_num = 0;
	stack = NULL;

	/* text = my_getline(&line, &line_size, file); */
	while (my_getline(&line, &line_size, file) != -1)
	{
		line_num++;
		opcode = strtok(NULL, " \n\t\r");

		if (opcode != NULL && opcode[0] != '#')
		{
			op_code_found = 0;
			for (a = 0 ; a < NUM_OP_CODES; a++)
			{
				cmp_result = strcmp(opcode, opcodes[a].opcode);
				if (cmp_result == 0)
				{
					opcodes[a].f(&stack, line_num);
					op_code_found = 1;
					break;
				}
			}
			if (op_code_found == 0)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
				fclose(file);
				free(line);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(file);
	free(line);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
