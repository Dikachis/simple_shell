#include "shell.h"
/**
 * is_buit - command environment
 * @line: wherever
 * @environ: add envi
 * Return: if pointers is success.
 */
int is_buit(char **line, char **environ)
{
	int chdir_val = 0;

	if (_strcmp(line[0], "exit") == 0 && line[1] == NULL)
	{
		free_dp(line);
		return (1);
	}

	if (_strcmp(line[0], "cd") == 0)
	{
		if (!line[1])
		{
			chdir_val = chdir("..");
			if (chdir_val != 0)
			{
				printf("Error changing directory\n");
				return (1);
			}
			return (1);
		}

		chdir_val = chdir(line[1]);

		if (chdir_val != 0)
		{
			printf("Error changing directory to: %s\n", line[1]);
			return (1);
		}
		return (1);
	}

	if ((_strcmp(line[0], "env") == 0) && line[1] == NULL)
		_printenv(environ);

	return (EXIT_SUCCESS);
}

/**
 * _printenv - prints the current environment
 * @environ: environment variable
 */
void _printenv(char **environ)
{
	int x = 0;

	for (; environ[x]; x++)

		_puts(environ[x]); /*imprime todo el environment*/
}
