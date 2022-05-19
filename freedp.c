#include "shell.h"
/**
 * free_dp - free all file
 * @line: double pointer to free
 *
 * Return: ptr null
 */

char **free_dp(char **line)
{
	int x;

	for (x = 0; line[x]; x++)
	{
		free(line[x]);
		line[x] = NULL;
	}
	free(line);
	line = NULL;
	return (NULL);
}
