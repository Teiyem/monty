#include "monty.h"

/**
 * add_stack_end - function prototype
 * Description: Adds a new node at the end of a stack_t list
 * @head: Pointer to the head of the list
 * @n: The integer to add to the list
 * Return: The address of the new node
 */
stack_t *add_stack_end(stack_t **head, const int n)
{
	stack_t *temp;
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_s_queue();
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}

	temp = *head;

	while (temp->next)
	{
		temp = temp->next;
	}

	node->prev = temp;
	temp->next = node;

	return (node);
}


