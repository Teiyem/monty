#include "monty.h"

/**
 * _rotl - Rotates the stack to the top
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *stack = NULL;
	stack_t *temp = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	stack = (*doubly)->next;
	temp = *doubly;

	for (; temp->next != NULL; temp = temp->next)
		;

	stack->prev = NULL;
	temp->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = temp;
	*doubly = stack;
}