
#include "shell.h"
/**
 *_puts - prints a string
 *@str: A pointer to an int that will be updated
 *
 *Return: void
 */
void _puts(char *str)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		_putchar(str[x]);
	}
	_putchar('\n');
}
