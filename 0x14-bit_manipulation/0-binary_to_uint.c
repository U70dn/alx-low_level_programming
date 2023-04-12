#include "main.h"

/**
 * binary_to_uint - converts a binary num to an unsigned int
 * @b:the  string containing the binary num
 *
 * Return: the converted num
 */
unsigned int binary_to_uint(const char *binary_string)
{
	int i;
	unsigned int decimal_value = 0;

	if (!binary_string)
		return (0);

	for (i = 0; binary_string[i]; i++)
	{
		if (binary_string[i] < '0' || binary_string[i] > '1')
			return (0);
		decimal_value = 2 * decimal_value + (binary_string[i] - '0');
	}

	return (decimal_value);
}
