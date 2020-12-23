#ifndef montyH
#define montyH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct prop_s - structure for the file
 * @buf: buffer
 * @stack: data struct
 * @file: File
 */
typedef struct prop_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
} prop_t;

/**
 * struct line_s - line content and number
 * @num: line
 * @con: content
 */
typedef struct line_s
{
	unsigned int num;
	char **con;
} line_t;

/**
 * struct arg_s - struct for arguments
 * @arg: argument
 * @flag: flag
 */
typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;
arg_t arg;

void analyze_file(FILE *file);
void analyze_line(line_t *line, char *buffer);
bool argument_c(char *t);
void push_c(line_t line, prop_t *p, char *opcode);
void (*funcs(line_t line, prop_t *p))(stack_t **, unsigned int);
void pall(stack_t **stack, unsigned int nl);
void push(stack_t **stack, unsigned int nl);
void frees(stack_t **stack);
bool comment_c(line_t line);
void npush(stack_t **stack, unsigned int nl);
void nop(stack_t **stack, unsigned int nl);
void pint(stack_t **stack, unsigned int nl);

#endif
