#include "shell.h"
/**
 * _env - prints the enviroment varibles.
 * @com: commands
**/
void _env(char **com)
{
	int i;
	char *s = *environ;

	if (com[1] != NULL)
		return;
	for (i = 0; s; i++)
	{
		write(STDIN_FILENO, s, _strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + i);
	}
}
