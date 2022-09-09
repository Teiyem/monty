#include "monty.h"

/**
 * _realloc - Function prototype
 * Description: Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with a call to malloc
 * @old_size: The size in bytes of the old memory block
 * @new_size: The new size in bytes of the new memory block
 * Return: A pointer to the first element of the array.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *array;
	char *temp;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		array = malloc(new_size);

		if (array == NULL)
			return (NULL);

		return (array);
	}

	array = malloc(sizeof(char) * new_size);

	if (array == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		temp = ptr;

		for (i = 0; i < old_size; i++)
			array[i] = temp[i];

		free(ptr);
	}
	return (array);
}