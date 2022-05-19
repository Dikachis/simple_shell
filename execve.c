#include "shell.h"
/**
 * _execev - Execute a programming exec
 * @line:  recieved from strtok the token
 * @argv: line of arguments of file
 * @num:  variablei internal
 * @isatty_val: is the tty
 * @envi: enviroment variable
 * Return: None
 */
void _execev(char **line, char *argv, int num, int isatty_val, char **envi)
{
	pid_t pid;
	int _exec = 0;

	if (line[0] == NULL)
		return;

	if (is_buit(line, envi) == 1)
		return;

	pid = fork();
	if (pid < 0)
	{
		printf("Error during fork\n");
		free_dp(line);
		exit(EXIT_FAILURE);
	}
	else if (pid != 0)
	{
		wait(NULL);
		return;
	}
	else
	{
		if (check_path(envi, line) == 0)
			_exec = execve(line[0], line, NULL);
		if (_exec < 0)
		{
			if (isatty_val == 1)
			{
				printf("%s: No such file or directory\n", argv);
				free(line);
				exit(EXIT_SUCCESS);
			}
			printf("%s: %d: %s: not found\n", argv, num, line[0]);
			free(line);
			exit(EXIT_FAILURE);
		}
		free_dp(line);
		exit(EXIT_SUCCESS);
	}
}
