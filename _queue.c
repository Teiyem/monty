#include "monty.h"

/**
 * _queue - function prototype
 * Description: Sets the format of the data to a queue (FIFO)
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	s_queue.lifo = 0;
}