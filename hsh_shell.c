#include "shell.h"

/**
 * main - Executes all main functions
 * @argc:  count to arguments
 * @av:  pointers with arguments
 * @env: wherever
 * Return: Nothing
 */

int main(int argc __attribute__((unused)), char **av, char **env)
{
	char *string = NULL, **line = NULL;
	int _num_prompt = 0, val_isatty = 0;

	while (1)
	{
		val_isatty = isatty(STDIN_FILENO);
		string = get_line(val_isatty);

	if (_strcmp(string, "exit\n") == 0)
	{
		free(string);
		exit(0);
	}

		if (string != NULL)
		{
			_num_prompt++;
			line = _strtok(string);
			_execev(line, av[0], _num_prompt, val_isatty, env);
			free(string);
			free(line);
		}
		val_isatty = 0;
	}
	return (0);
}
