#include "monty.h"

/**
 * _pop - function prototype
 * Description: Removes the top element of the stack
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *stack;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_s_queue();
		exit(EXIT_FAILURE);
	}
	stack = *doubly;
	*doubly = (*doubly)->next;
    
	free(stack);
}