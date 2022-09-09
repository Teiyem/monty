#include "monty.h"

/**
 * _stack - function prototype
 * Description: Sets the format for the data to a stack (LIFO)
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	s_queue.lifo = 1;
}