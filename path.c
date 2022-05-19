#include "shell.h"
/**
 * _path -  path execute commands
 * @environ: Environ variable
 * Return: token
 **/
char **_path(char **environ)
{
	int location = 0;
	char **token;

	for (; environ[location] != NULL; location++)
	{
		if (environ[location][0] == 'P' && environ[location][2] == 'T')
		{
			token = &(environ[location]);
		}
	}
	return (token);
}
