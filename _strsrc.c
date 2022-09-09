#include "monty.h"

/**
 * _strsrc - Searches string contains a specified char
 * @s: The string to search
 * @c: The character to search for
 * Return: 1 if the character c is found in the string s, and 0 otherwise
 */
int _strsrc(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			break;
		i++;
	}
	if (s[i] == c)
		return (1);
	else
		return (0);
}

