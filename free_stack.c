#include "monty.h"

/**
 * free_stack - function prototype
 * Description: Frees a stack_t list
 * @head: Pointer to the head of the list
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = temp->next;
		free(temp);
	}
}