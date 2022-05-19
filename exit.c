#include "shell.h"
/**
 * _exit_function - function to print
 * @void: the exit
 * Return: none
 */
void _exit_function(void)
{
	kill(getpid(), SIGTERM);
}
