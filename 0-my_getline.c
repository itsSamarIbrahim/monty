#include "monty.h"

/**
 *
 */

/**
char *my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line, *new_line;
	int position, ch, buf_size = BUFFER_SIZE, i;

	line = (char *)malloc(sizeof(char) * buf_size);
	if (line == NULL)
	{
		fprintf(stderr, "ALLOCATION FAILED\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ch = getchar();

		if (ch == EOF || ch == '\n')
		{
			line[position] = '\0';
			break;
		}
		else
		{
			line[position] = ch;
		}
		position++;

		if (position >= buf_size - 1)
		{
			buf_size = buf_size + BUFFER_SIZE;
			new_line = (char *)malloc(buf_size * sizeof(char));
			if (new_line == NULL)
			{
				fprintf(stderr, "ALLOCATION FAILED\n");
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < position; i++)
				new_line[i] = line[i];
			free(line);
			line = new_line;
		}
	}

	return (line);
}
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
	size_t pos;
	int c;

    if (*lineptr == NULL) {
        *lineptr = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (*lineptr == NULL) {
            return -1;
        }
        *n = BUFFER_SIZE;
    }

    pos = 0;

    while (1) {
        c = fgetc(stream);

        if (c == EOF || c == '\n') {
            (*lineptr)[pos] = '\0';
            return pos;
        } else {
            (*lineptr)[pos] = c;
        }
        pos++;

        if (pos >= *n - 1) {
            return -1;
        }
    }
}
