#include "monty.h"

s_queue_t s_queue;

/**
 * free_s_queue - function prototype
 * Description: Frees the stack and the buffer and closes the file.
 * Return: void
 */
void free_s_queue(void)
{
	free_stack(s_queue.head);
	free(s_queue.buffer);
	fclose(s_queue.fd);
}

/**
 * init_s_queue - Initializes the queue
 * @fd: The file descriptor of the file to be read
 * Return: void
 */
void init_s_queue(FILE *fd)
{
	s_queue.lifo = 1;
	s_queue.cont = 1;
	s_queue.arg = NULL;
	s_queue.head = NULL;
	s_queue.fd = fd;
	s_queue.buffer = NULL;
}

/**
 * check_input - Checks if the user has provided a file to read from, 
 * and if so, it opens it
 * @param argc The number of arguments passed to the program.
 * @param argv An array of pointers to the command line arguments.
 * Return: The file descriptor of the file that was opened.
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *file;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - Program entry point
 * Description: Reads the file line by line, tokenize the line,
 * and calls the appropriate opcode function
 * @argc: The number of arguments passed to the program.
 * @argv: The array of strings arguments that were passed to the program
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file;
	size_t size = 256;
	ssize_t len = 0;
	char *lines[2] = {NULL, NULL};

	file = check_input(argc, argv);
	init_s_queue(file);
	len = getline(&s_queue.buffer, &size, file);

	while (len != -1)
	{
		lines[0] = _strtok(s_queue.buffer, " \t\n");

		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcode(lines[0]);

			if (!f)
			{
				dprintf(2, "L%u: ", s_queue.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_s_queue();
				exit(EXIT_FAILURE);
			}
			s_queue.arg = _strtok(NULL, " \t\n");
			f(&s_queue.head, s_queue.cont);
		}
		len = getline(&s_queue.buffer, &size, file);
		s_queue.cont++;
	}

	free_s_queue();
	return (0);
}
