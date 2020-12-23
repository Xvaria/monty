#include "monty.h"

/**
 * frees - free stacks
 * @stack: head of stack
 */
void frees(stack_t **stack)
{
	stack_t *pt = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		pt = (*stack)->next;
		free(*stack);
		*stack = pt;
	}
}

/**
 * comment_c - analyze line
 * @line: struct line_t
 * Return: true or false
 */
bool comment_c(line_t line)
{
	if (!line.content[0] || line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}
	return (false);
}
