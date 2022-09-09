#include "monty.h"

/**
 * _pall - function prototype
 * Description: Prints all the values on the stack, starting from the top of the stack
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *stack;
	(void)cline;

	stack = *doubly;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}