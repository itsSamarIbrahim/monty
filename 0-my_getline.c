#include "monty.h"

/**
 *
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos;
	int c;

	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (*lineptr == NULL)
			return (-1);
		*n = BUFFER_SIZE;
	}

	pos = 0;

	while (1)
	{
		c = fgetc(stream);

		if (c == EOF || c == '\n')
		{
			(*lineptr)[pos] = '\0';
			return (pos);
		}
		else
		{
			(*lineptr)[pos] = c;
		}
		pos++;

		if (pos >= *n - 1)
		{
			return (-1);
		}
	}
}
