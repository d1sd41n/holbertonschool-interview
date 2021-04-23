#include "sort.h"

/**
 * check_tree - doc
 *
 * @array: doc
 * @size: doc
 * @size_init: doc
 * @i: doc
 *
 **/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

int n, branch1, branch2;
size_t aux_x1, aux_x2;

aux_x1 = i * 2 + 1;
aux_x2 = aux_x1 + 1;

branch1 = array[aux_x1];
branch2 = array[aux_x2];

if (((aux_x1 < size) && (aux_x2 < size) && (branch1 >= branch2
&&branch1 > array[i]))
|| ((aux_x1 == size - 1) && branch1 > array[i]))
{
n = array[i];

array[i] = branch1;

array[aux_x1] = n;
print_array(array, size_init);
}
else if ((aux_x1 < size) && (aux_x2 < size) &&
	 (branch2 > branch1 && branch2 > array[i]))
{
n = array[i];

array[i] = branch2;

array[aux_x2] = n;

print_array(array, size_init);

}
if (aux_x1 < size - 1)
check_tree(array, size_init, size, aux_x1);
if (aux_x2 < size - 1)
check_tree(array, size_init, size, aux_x2);
}

void heap_sort(int *array, size_t size)
{
size_t i, size_init = size;
int n;

if (!array)
return;
for (i = 0; i < size / 2 ; i++)
{
check_tree(array, size_init, size, size / 2 - 1 - i);
}
for (i = 0; i < size_init - 1; i++)
{
n = array[0];

array[0] = array[size - 1 - i];
array[size - 1 - i] = n;

print_array(array, size_init);

check_tree(array, size_init, size - i - 1, 0);
}

}
