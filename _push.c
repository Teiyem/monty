#include "monty.h"

/**
 * _push - function prototype
 * Description: Pushes an integer onto the doubly linked list
 * @doubly: Pointer to the head of the doubly linked list
 * @cline: The line number
 * Return: void
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, 
    int x;

	if (s_queue.arg == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_s_queue();
		exit(EXIT_FAILURE);
	}

	for (x = 0; s_queue.arg[x] != '\0'; x++)
	{
		if (!isdigit(s_queue.arg[x]) && s_queue.arg[x] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_s_queue();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(s_queue.arg);

	if (s_queue.lifo == 1)
		add_stack(doubly, n);
	else
		add_stack_end(doubly, n);
}