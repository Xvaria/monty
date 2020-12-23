#include "monty.h"

/**
 * frees - free stacks
 * @stack head of stack
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
