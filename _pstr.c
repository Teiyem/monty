#include "monty.h"

/**
 * _pstr - function prototype
 * Description: Prints the string of the stack
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *stack;
	(void)cline;

	stack = *doubly;

	while (stack && stack->n > 0 && stack->n < 128)
	{
		printf("%c", stack->n);
		stack = stack->next;
	}

	printf("\n");
}
