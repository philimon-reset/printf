#include "holberton.h"

/**
 * _numlen - counts the number of digits in a number
 * @num: number to be counted
 * @base: base of the number
 *
 * Return: length of the number
 */
int _numlen(int num, int base)
{
	int len = 0;

	while (num)
	{
		if (base == 10)
		{
			num /= 10;
			len++;
		}
		else if (base == 2)
		{
			num >>= 1;
			len++;
		}
		else if (base == 8)
		{
			num /= 8;
			len++;
		}
		else if (base == 16)
		{
			num /= 16;
			len++;
		}
	}
	return (len);
}

/**
 * looper - function that returns a function
 * @format: character to be checked
 *
 * Return: void
 */
void (*looper(char format))(va_list, int *)
{
	map mapping[] = {
		{'c', print_char}, {'d', print_int},
		{'i', print_int}, {'s', print_str},
		{'x', print_hex_x}, {'X', print_hex_X},
		{'S', print_S}, {'b', print_bin},
		{'o', print_octal}, {'r', print_rev},
		{'R', print_rot13}
	};
	int i = 0;
	void (*f)(va_list, int*);

	f = NULL;

	for (; i < 11; i++)
	{
		if (format == mapping[i].conversion_specifier)
		{
			f = mapping[i].function;
			break;
		}
	}
	return (f);
}

/**
 * transform - helper function to map a letter with it's rot13 encoding
 * @x: char to be encoded
 *
 * Return: the encoded char
 */
char transform(char x)
{
	char one[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char two[52] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0;
	char replacement = x;

	while (i < 52)
	{
		if (x == one[i])
		{
			replacement = two[i];
			break;
		}
		i++;
	}
	return (replacement);
}
