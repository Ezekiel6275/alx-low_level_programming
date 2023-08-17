#include "main.h"

/**
 * print_most_numbers - Prints numbers excluding 2 and 4
 *
 * This function prints the numbers from 0 to 9, excluding 2 and 4.
 * It uses the _putchar function to display the numbers.
 */
void print_most_numbers(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
	{
	if (!(c == '2' || c == '4'))
	_putchar(c);
	}
	_putchar('\n');
}
