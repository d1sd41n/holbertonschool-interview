#include "search_algos.h"


/**
 * advanced_binary - doc
 *
 * @array: doc
 * @size: doc
 * @value: doc
 *
 * Return: doc
 */
int advanced_binary(int *array, size_t size, int value)
{
size_t i, aux, aux2;
int tmp;

if (!array)
return (-1);
printf("Searching in array: ");
aux2 = 0;
for (i = 0; i < size; i++)
{
if (i == size - 1)
printf("%d\n", array[i]);
else
printf("%d, ", array[i]);
}
if (size == 1 && array[0] != value)
return (-1);
aux = (size - 1) / 2;
if (array[aux] == value)
{
if (array[aux - 1] < value)
return (aux);
}
if (array[aux] < value)
{
aux2 += aux + 1;
array += aux + 1;
if (size % 2 != 0)
aux--;
}
aux++;
tmp = advanced_binary(array, aux, value);
if (tmp != -1)
return (tmp + aux2);
return (-1);
}
