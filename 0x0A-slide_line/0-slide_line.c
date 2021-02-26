#include "slide_line.h"

int left_l(int *line, size_t size);
int right_l(int *line, size_t size);


/**
* slide_line - docs
* @line: docs
* @size: docsay
* @direction: docs
* Return: docs
*/
int slide_line(int *line, size_t size, int direction)
{

if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
{
return (0);
}

if (direction == SLIDE_LEFT)
{
return (left_l(line, size));
}

return (right_l(line, size));
}

/**
* right_l - docs
* @line: docs
* @size: docs
* Return: docs
*/
int right_l(int *line, size_t size)
{
size_t right = size - 1, i;
int aux1 = 0, aux2 = 0;


for (i = size - 1; i < size; i--)
{
if (line[i] != 0 && aux1 == 0)
aux1 = line[i];

else if (line[i] != 0 && aux1 != 0)
aux2 = line[i];

if (aux1 != 0 && aux2 != 0)
{
if (aux1 == aux2)
{
line[right--] = aux1 + aux2;
aux1 = 0;
aux2 = 0;
}
else
{
line[right--] = aux1;
aux1 = aux2;
aux2 = 0;
if (i == 0)
line[right--] = aux1;
}
}

else if (aux1 != aux2 && i == 0)
line[right--] = aux1;
}

for (i = 0; i < right + 1; i++)
line[i] = 0;
return (1);
}

/**
* left_l - docs
* @line: docs
* @size: docs
* Return: docs
*/
int left_l(int *line, size_t size)
{
size_t left = 0, right;
int aux1 = 0, aux2 = 0;


for (right = 0; right < size; right++)
{
if (line[right] != 0 && aux1 == 0)
aux1 = line[right];

else if (line[left] != 0 && aux1 != 0)
aux2 = line[right];

if (aux1 != 0 && aux2 != 0)
{
if (aux1 == aux2)
{
line[left++] = aux1 + aux2;
aux1 = 0;
aux2 = 0;
}
else
{
line[left++] = aux1;
aux1 = aux2;
aux2 = 0;
if (right == size - 1)
line[left++] = aux1;
}
}
else if (aux1 != aux2 && right == size - 1)
line[left++] = aux1;

}
for (right = left; right < size; right++)
line[right] = 0;
return (1);
}
