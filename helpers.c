#include "holberton.h"

/**
 * reverse_string - reverses a string
 * @string: string to be reversed
 * @length: length of the string
 *
 * Return: void
 */
void reverse_string(char *string, int length)
{
	int first = 0, last = length - 1;
	char temp;

	while (first < last)
	{
		temp = string[first];
		string[first] = string[last];
		string[last] = temp;
		first++;
		last--;
	}
}

/**
 * _strlen - counts the length of a string
 * @string: string to be counted
 *
 * Return: length of the string
 */
int _strlen(char *string)
{
	int len = 0;

	while (*string++)
		len++;
	return (len);
}

/**
 * _itoa - converts a number to a string
 * @num: number to be converted
 * @string: char buffer to store the string in
 *
 * Return: pointer to the final string
 */
char *_itoa(int num, char *string)
{
	int i = 0, is_negative = 0;

	if (num == 0)
	{
		string[i] = '0';
		string[i++] = '\0';
		return (string);
	}
	if (num < 0)
	{
		is_negative = 1;
		num *= -1;
	}
	while (num)
	{
		string[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	if (is_negative)
	{
		string[i] = '-';
		i++;
	}
	string[i] = '\0';
	reverse_string(string, _strlen(string));
	return (string);
}

/**
 * print - prints the given string to stdout
 * @string: string to be printed
 * @count: integer to be incremented for every char printed
 *
 * Return: void
 */
void print(char *string, int *count)
{
	while (*string != '\0')
	{
		_putchar(*string, count);
		string++;
	}
}

/**
 * _putchar -  prints a char to stdout
 * @c: char to be printed
 * @count: int to be incremented for the char printed
 *
 * Return: void
 */
void _putchar(char c, int *count)
{
	write(1, &c, 1);
	*count++;
}
