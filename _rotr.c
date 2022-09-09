#include "monty.h"

/**
 * _rotr - function prototype
 * Description: Reverses the stack
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *stack = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	stack = *doubly;

	for (; stack->next != NULL; stack = stack->next)
		;

	stack->prev->next = NULL;
	stack->next = *doubly;
	stack->prev = NULL;
	(*doubly)->prev = stack;
	*doubly = stack;
}
