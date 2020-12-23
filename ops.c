#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: head of stack
 * @nl: number
 */
void push(stack_t **stack, unsigned int nl)
{
	stack_t *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nl);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}

	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - print all the values on the stack, starting from the top of the stack
 * @stack: head of stack
 * @nl: number
 */
void pall(stack_t **stack, unsigned int nl)
{
	stack_t *pt;
	(void)nl;

	pt = *stack;
	while (pt)
	{
		printf("%d\n", pt->n);
		pt = pt->next;
	}
}

/**
 * nop - nothing
 * @stack: head of stack
 * @nl: number
 */
void nop(stack_t **stack, unsigned int nl)
{
	(void)stack;
	(void)nl;
}

/**
 * npush - pushes for queue
 * @stack: head of stack
 * @nl: number
 */
void npush(stack_t **stack, unsigned int nl)
{
	stack_t *last, *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nl);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		frees(stack);
		exit(EXIT_FAILURE);
	}
	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
