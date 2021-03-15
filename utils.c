#include "holberton.h"

/**
 * print_char - wrapper for _putchar to make it compatible with map type
 * @args: variable arguments passed to _printf
 * @count: int to be used by _putchar, see _putchar in helpers.c
 *
 * Return: void
 */
void print_char(va_list args, int *count)
{
	_putchar(va_arg(args, int), count);
}

/**
 * print_str - wrapper function for print to make it compatible with map type
 * @args: variable arguments passed to _printf
 * @count: int to be used by print, see description for print in helpers.c
 *
 * Return: void
 */
void print_str(va_list args, int *count)
{
	print(va_arg(args, char *), count);
}

/**
 * print_int - prints an integer to stdout;
 * @args: variable arguments passed to _printf
 * @count: int to be used by print, see description for print in helpers.c
 *
 * Return: void
 */
void print_int(va_list args, int *count)
{
	char *number_string;
	int num = va_arg(args, int);

	number_string = malloc(sizeof(char) * (_numlen(num) + 1));
	if (number_string != NULL)
	{
		_itoa(num, number_string);
		print(number_string, count);
	}
}

void print_hex_x(va_list args, int *count)
{
	char *hex_string;
	int num = va_arg(args, int);
	int i = 0;

	hex_string = malloc(sizeof(char) * (hexlen(num) + 1));
	if (hex_string != NULL)
	{
		_itoa(num, hex_string);
	}
	print(hex_string, count);
}

void print_hex_X(va_list args, int *count)
{
	char *hex_string;
	int num = va_arg(args, int);
	int i = 0;

	hex_string = malloc(sizeof(char) * (hexlen(num) + 1));
	if (hex_string != NULL)
	{
		_itoa(num, hex_string);
		for (; i < hexlen(num); i++)
		{
			if (hex_string[i] >= '97' && hex_string[i] <= '122')
			{
				hex_string[i] -= 32;
			}
		}
	}
	print(hex_string, count);
}
