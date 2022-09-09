#include "monty.h"

/**
 * _pchar - function prototype
 * Description: Prints the value at the top of the stack as a character
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_s_queue();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_s_queue();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}