#include "monty.h"

/**
 * _pint - function prototype
 * Description: Prints the value at the top of the stack
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_s_queue();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}