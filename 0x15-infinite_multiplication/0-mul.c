#include "holberton.h"

/**
 * my_writer - doc
 * @str: doc
 * @l: doc
 *
 * Return: doc
 */

void my_writer(char *str, int l)
{
int i, j;

i = j = 0;
while (i < l)
{
if (str[i] != '0')
j = 1;
if (j || i == l - 1)
_putchar(str[i]);
i++;
}

_putchar('\n');
free(str);
}

/**
 * mul - doc
 * @n: doc
 * @num: doc
 * @num_index: doc
 * @dest: doc
 * @dest_index: doc
 *
 * Return: doc
 */
char *mul(char n, char *num, int num_index, char *dest, int dest_index)
{
int j, k, mul, mulrem, add, addrem;

mulrem = addrem = 0;
for (j = num_index, k = dest_index; j >= 0; j--, k--)
{
mul = (n - '0') * (num[j] - '0') + mulrem;
mulrem = mul / 10;
add = (dest[k] - '0') + (mul % 10) + addrem;
addrem = add / 10;
dest[k] = add % 10 + '0';
}
for (addrem += mulrem; k >= 0 && addrem; k--)
{
add = (dest[k] - '0') + addrem;
addrem = add / 10;
dest[k] = add % 10 + '0';
}
if (addrem)
{
return (NULL);
}
return (dest);
}

/**
 * in_oprigt - doc
 * @str: doc
 * @l: doc
 *
 * Return: doc
 */
void in_oprigt(char *str, int l)
{
int i;

for (i = 0; i < l; i++)
str[i] = '0';
str[i] = '\0';
}

/**
 * t_x_op - doc
 * @av: doc
 *
 * Return: doc
 */

int t_x_op(char **av)
{
int i, j;

for (i = 1; i < 3; i++)
{
for (j = 0; av[i][j]; j++)
{
if (av[i][j] < '0' || av[i][j] > '9')
return (1);
}
}
return (0);
}

/**
 * main - doc
 * @argc: doc
 * @argv: doc
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
int l1, l2, ln, ti, i;
char *a;
char *t;
char e[] = "Error\n";

if (argc != 3 || t_x_op(argv))
{
for (ti = 0; e[ti]; ti++)
_putchar(e[ti]);
exit(98);
}
for (l1 = 0; argv[1][l1]; l1++)
;
for (l2 = 0; argv[2][l2]; l2++)
;
ln = l1 + l2 + 1;
a = malloc(ln * sizeof(char));
if (a == NULL)
{
for (ti = 0; e[ti]; ti++)
_putchar(e[ti]);
exit(98);
}
in_oprigt(a, ln - 1);
for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)
{
t = mul(argv[2][ti], argv[1], l1 - 1, a, (ln - 2) - i);
if (t == NULL)
{
for (ti = 0; e[ti]; ti++)
_putchar(e[ti]);
free(a);
exit(98);
}
}
my_writer(a, ln - 1);
return (0);
}
