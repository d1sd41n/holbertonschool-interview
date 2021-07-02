#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * ft_nod - doc
 * @list: doc
 * @str: doc
 * Return: doc
 */
List *ft_nod(List **list, char *str)
{
List *new;

new = malloc(sizeof(List));
if (new == NULL)
return (NULL);
new->str = strdup(str);
if (new->str == NULL)
{
free(str);
return (NULL);
}
new->next = new;
new->prev = new;
*list = new;
return (new);
}

/**
* add_node_end - doc
* @list: doc
* @str: doc
* Return: doc
*/
List *add_node_end(List **list, char *str)
{
List *new, *tmp, *aux;

if (list == NULL)
return (NULL);
if (*list == NULL)
return (ft_nod(list, str));

aux = *list;
new = malloc(sizeof(List));
if (new == NULL)
return (NULL);
new->str = strdup(str);
if (new->str == NULL)
{
free(new);
return (NULL);
}
new->next = aux;
new->prev = aux->prev;
tmp = aux->prev;
aux->prev = new;
tmp->next = new;

return (new);
}

/**
* add_node_begin - doc
* @list: doc
* @str: doc
* Return: doc
*/
List *add_node_begin(List **list, char *str)
{
List *new, *tmp, *aux;

if (list == NULL)
return (NULL);
if (*list == NULL)
return (ft_nod(list, str));

aux = *list;
new = malloc(sizeof(List));
if (new == NULL)
return (NULL);
new->str = strdup(str);
if (new->str == NULL)
{
free(new);
return (NULL);
}
new->next = aux;
new->prev = aux->prev;
tmp = aux->prev;
aux->prev = new;
tmp->next = new;
*list = new;

return (new);

}
