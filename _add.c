#include "monty.h"

/**
 * _add - function prototype
 * Description: Adds the top two elements of the stack
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *stack = NULL;

	stack = *doubly;

	for (; stack != NULL; stack = stack->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_s_queue();
		exit(EXIT_FAILURE);
	}

	stack = (*doubly)->next;
	stack->n += (*doubly)->n;
	_pop(doubly, cline);
}