#include "palindrome.h"
/**
 * is_palindrome - cdoc
 * @n: docs
 * Return: docs
 */
int is_palindrome(unsigned long n)
{

	unsigned long aux;
	unsigned long r, op = 0;

	aux = n;
	while (n > 0)
	{
		r = n % 10;
		op = (op * 10) + r;
		n = n / 10;
	}
	if (aux == op)
	{
		return (1);
	}

	return (0);
}