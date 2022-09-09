#include "monty.h"

/**
 * _calloc - Function prototype
 * Description: Allocates memory for an array, using malloc
 * @nmemb: The number of elements to allocate.
 * @size: The size of the memory block, in bytes.
 * Return: A pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *array;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	if (size >= UINT_MAX / nmemb)
		return (NULL);

	array = malloc(size * nmemb);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		array[i] = 0;

	return (array);
}