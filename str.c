#include "shell.h"
/**
 * _strcmp - Compares two strings
 * @s1: The string to 1t
 * @s2: The string to 1t
 * Return: An interer to array
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strlen - Return the lenght of a string
 * @s: The string to test
 *
 * Return: Integer: The lenght of a string
 */
int _strlen(char *s)
{
	int contador = 0, indice = 0;

	while (s[indice] != '\0')
	{
		contador++;
		indice++;
	}
	return (contador);
}

/**
 *_strdup - back a pointer to array
 *@str: pointer to array
 *Return: Always an array dinamic
 */

char *_strdup(char *str)
{
	char *arr;
	unsigned int i, size;

	if (str == 0)
		return (NULL);

	size = _strlen(str) + 1;

	arr = (char *)malloc(size * sizeof(char));

	if (arr == 0)
		return (NULL);

	for (i = 0; *(str + i) != '\0'; i++)
		*(arr + i) = *(str + i);

	*(arr + i) = '\0';

	return (arr);
}

/**
 *_equal - find sames characters
 *@dest: initial segment
 *@src: prefix
 *Return: Always int
 */
int _equal(char *dest, char *src)
{
	int i;

	i = 0;

	while (*dest + i != '\0' && *src + i != '\0')
	{
		if (*dest != *src)
			return (0);
		dest++;
		src++;
	}

	return (*src == '\0');
}

/**
 *_strstr - find
 *@haystack: initial segment
 *@needle: prefix
 *Return: Always char
 */

char *_strstr(char *haystack, char *needle)
{
	if (*haystack == '\0')
		return (0);

	if (haystack[0] != needle[0])
		return (NULL);

	if (*needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		if ((*haystack == *needle) && _equal(haystack, needle))
			return (haystack);
		haystack++;
	}

	return (0);
}
