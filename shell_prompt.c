#include "shell.h"
/**
 * main - starts the shell loop
 *
 * Return: exit_success
 */
int main(void)
{
	int stat;

	do {
	stat = promptShell();
	} while (stat != _SHELL_END);

	return (EXIT_SUCCESS);
}
/**
 * promptShell - stats the shell prompt
 *
 * Return: returns value to continue or stop shell
 */
int promptShell(void)
{
	char *buffer = NULL;
	char *pPath = NULL;
	char **args = NULL;
	size_t length = 0;
	ssize_t getCheck;
	int stat = _NORMAL;

	stat = _NORMAL;
	write(STDOUT_FILENO, "$ ", 2);
	getCheck = getline(&buffer, &length, stdin);

	if (getCheck == -1)
	{
		stat = _SHELL_END;
		write(STDOUT_FILENO, "\n", 1);
	}
	else if (getCheck == 1)
		stat = _SKIP;

	if (stat == _NORMAL)
	{
		args = getToken(&buffer, "' '\n\t\r");
		stat = built_ins(args);
	}

        if (stat == _NORMAL && args[0][0] != '.')
	        pPath = getPathArgs(args[0]);

	if (stat == _NORMAL)
                execute(pPath ? pPath : args[0], args);

	free(args);
	free(pPath);
	free(buffer);
	return (stat);
}
/**
 * getToken - tokenizes the string
 *
 * @buf: buffer where string is held
 * @pattern: the demiliter
 * Return: tokenized string of pointers
 */
char **getToken(char **buf, char *pattern)
{
	int i = 1;
	char *tok;
	char **args;
	unsigned int tokCount;

	tokCount = countToks(*buf, pattern);

	tok = strtok(*buf, pattern);
	if (tok == NULL)
		perror("no command passed: "), exit(EXIT_FAILURE);
	args = malloc(sizeof(char *) * (tokCount + 1));
	if (args == NULL)
		perror("Error in Allocation"), exit(EXIT_FAILURE);
	args[0] = tok;

	while (tok != NULL)
	{
		tok = strtok(NULL, pattern);
		if (tok != NULL)
			args[i] = tok, i++;
	}
	args[i] = NULL;
	return (args);
}
/**
 * execute - executes the command with its arguements
 *
 * @arg: the command
 * @args: arguements
 */
void execute(char *arg, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(arg, args, NULL) == -1)
		{
			perror("Execute command failed");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid == -1)
		perror("Fork error");
	else
		wait(NULL);
}
