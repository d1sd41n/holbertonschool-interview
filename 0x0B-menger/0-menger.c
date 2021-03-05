#include "menger.h"

/**
* menger - docs
* @level: docs
*/
void menger(int level)
{
char c;
int i, j, aux1, aux2, char_i;

char_i = pow(3, level);
for (i = 0; i < char_i; i++)
{

for (j = 0; j < char_i; j++)
{

c = '#';
aux1 = i;
aux2 = j;

while (aux1 > 0)
{

if (aux1 % 3 == 1 && aux2 % 3 == 1)
c = ' ';

aux1 /= 3;
aux2 /= 3;
}

printf("%c", c);
}

printf("\n");
}
}
