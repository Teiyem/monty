#include "monty.h"

/**
 * add_stack - function prototype
 * Description: Adds a new node at the beginning of a stack_t list
 * @head: Pointer to the head of the list
 * @n: The integer to add to the list
 * Return: The address of the new node
 */
stack_t *add_stack(stack_t **head, const int n)
{
    stack_t *temp;

    if (head == NULL)
        return (NULL);

    temp = malloc(sizeof(stack_t));

    if (temp == NULL)
    {
        dprintf(2, "Error: malloc failed\n");
        free_s_queue();
        exit(EXIT_FAILURE);
    }
    temp->n = n;

    if (*head == NULL)
    {
        temp->next = *head;
        temp->prev = NULL;
        *head = temp;
        return (*head);
    }

    (*head)->prev = temp;
    temp->next = (*head);
    temp->prev = NULL;
    *head = temp;

    return (*head);
}