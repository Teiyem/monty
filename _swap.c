#include "monty.h"

/**
 * _swap - function prototype
 * Description: Swaps the top two elements of the stack
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *stack = NULL;

	stack = *doubly;

	for (; stack != NULL; stack = stack->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_s_queue();
		exit(EXIT_FAILURE);
	}

	stack = *doubly;
	*doubly = (*doubly)->next;
	stack->next = (*doubly)->next;
	stack->prev = *doubly;
	(*doubly)->next = stack;
	(*doubly)->prev = NULL;
}
