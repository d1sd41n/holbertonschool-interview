#include "holberton.h"

/**
* _strlen - Fdc
* @s: sdc
* Return: dc
**/

int _strlen(char *s)
{
if (*s == '\0')
{
return (0);
}
s++;
return (_strlen(s) + 1);
}

/**
* _cmp - dc
* @s1: v
* @s2: dc
* @i: dc
* @j: dc
* @wc: dc
* @lwc: ldc
* @len: ldc
* Return: 1dc
**/

int _cmp(char *s1, char *s2, int i, int j, int wc, int lwc, int len)
{
if (s2[j] == '\0' && (s2[j - 1] == '*' || s2[j - 1] == s1[len - 1]))
return (1);
if (s2[j] == '*')
{
lwc = ++j;
wc = 1;
return (_cmp(s1, s2, i, j, wc, lwc, len));
}
if (s2[j] == s1[i])
{
i++;
j++;
wc = 0;
return (_cmp(s1, s2, i, j, wc, lwc, len));
}
if (s1[i] != s2[j] && wc == 1)
{
if (s1[i] == '\0')
return (0);
i++;
return (_cmp(s1, s2, i, j, wc, lwc, len));
}
if (s1[i] == '\0')
return (0);
if (s1[i] != s2[j] && wc == 0)
{
j = lwc;
wc = 1;
if (lwc == 0)
return (0);
return (_cmp(s1, s2, i, j, wc, lwc, len));
}
return (0);
}

/**
* wildcmp - dc
* @s1: dc
* @s2: dc
* Return: dc
*/

int wildcmp(char *s1, char *s2)
{
int i = 0, j = 0, wc = 1, lwc = 0, len;

len = _strlen(s1);

return (_cmp(s1, s2, i, j, wc, lwc, len));
}
