#include "monty.h"

/**
 * funcs - search function
 * @line: struct line_t
 * @p: struct prop_t
 * Return: any function
 */
void (*funcs(line_t line, prop_t *p))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}
	};
	if (comment_c(line))
		return (nop);
	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, line.con[0]) == 0)
		{
			push_c(line, p, op[i].opcode);
			if (arg.flag == 1 && strcmp(op[i].opcode, "push") == 0)
			{
				if (line.con)
					free(line.con);
				return (npush);
			}
			free(line.con);
			return (op[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line.num, line.con[0]);
	free(line.con);
	free(p->buf);
	frees(&(p->stack));
	fclose(p->file);
	free(p);
	exit(EXIT_FAILURE);
}

/**
 * push_c - check if push opcode is being used
 * @line: struct line_t
 * @p: struct prop_t
 * @opcode: struct instruction_t
 */
void push_c(line_t line, prop_t *p, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !argument_c(line.con[1]))
	{
		free(line.con);
		fprintf(stderr, "L%d: usage: push integer\n", line.num);
		free(p->buf);
		frees(&(p->stack));
		fclose(p->file);
		free(p);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.con[1]);
}

/**
 * argument_c - verify argument
 * @t: token
 * Return: true or false
 */
bool argument_c(char *t)
{
	unsigned int i;

	if (!t)
		return (false);

	for (i = 0; t[i]; i++)
	{
		if (t[0] == '-')
			continue;
		if (t[i] < '0' || t[i] > '9')
		{
			return (false);
		}
	}
	return (true);
}

/**
 * analyze_file - read and analyze file
 * @file: script
 */
void analyze_file(FILE *file)
{
	size_t s = 0;
	prop_t *p = NULL;
	line_t line;

	p = malloc(sizeof(prop_t));
	if (!p)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.num = 0;
	line.con = NULL;

	p->file = file;
	p->stack = NULL;
	p->buf = NULL;

	while (getline(&(p->buf), &s, p->file) != -1)
	{
		line.num++;
		analyze_line(&line, p->buf);
		if (line.con)
			funcs(line, p)(&(p->stack), line.num);
	}

	free(p->buf);
	frees(&(p->stack));
	fclose(p->file);
	free(p);
}

/**
 * analyze_line - tokenizes a lines of text
 * @line: struct line_t
 * @buffer: string
 */
void analyze_line(line_t *line, char *buffer)
{
	unsigned int i;
	char *t = NULL;

	line->con = malloc(sizeof(char *) * 3);
	if (!line->con)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	t = strtok(buffer, " '\n'");
	for (i = 0; t && i < 2; i++)
	{
		line->con[i] = t;
		t = strtok(NULL, " \n");
	}

	line->con[i] = NULL;
}
