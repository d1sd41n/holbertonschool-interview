#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint - doc
* @h: doc
* Return: doc
*/
size_t print_listint(const listint_t *h)
{
const listint_t *aux;
unsigned int n; /* number of nodes */

aux = h;
n = 0;
while (aux != NULL)
{
printf("%i\n", aux->n);
aux = aux->next;
n++;
}
return (n);
}

/**
* add_nodeint_end - doc
* @head: doc
* @n: doc
* Return: doc
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *n_node;
listint_t *aux;

aux = *head;
n_node = malloc(sizeof(listint_t));
if (n_node == NULL)
return (NULL);
n_node->n = n;
n_node->next = NULL;
if (*head == NULL)
*head = n_node;
else
{
while (aux->next != NULL)
	aux = aux->next;
aux->next = n_node;
}
return (n_node);
}

/**
* free_listint - doc
* @head: doc
* Return: doc
*/
void free_listint(listint_t *head)
{
listint_t *aux;

while (head != NULL)
{
aux = head;
head = head->next;
free(aux);
}
}
