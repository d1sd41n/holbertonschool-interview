#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - prints all elements of a listint_t list
 * @head: pointer to head of list
 * @number: the numbre to introduce in the list
 * Return: address of the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nodo_nuevo, *nodo_act;

	nodo_act = *head;
	nodo_nuevo = malloc(sizeof(listint_t));
	if (!nodo_nuevo)
		return (NULL);
	nodo_nuevo->next = NULL;
	nodo_nuevo->n = number;
	if ((*head)->n >= nodo_nuevo->n || !*head)
	{
		nodo_nuevo->next = *head;
		*head = nodo_nuevo;
	}
	else
	{
		while (nodo_act->next->n < nodo_nuevo->n && nodo_act->next != NULL)
			nodo_act = nodo_act->next;
		nodo_nuevo->next = nodo_act->next;
		nodo_act->next = nodo_nuevo;
	}
	return (nodo_nuevo);
}
