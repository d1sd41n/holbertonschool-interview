#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* insert_node - new node.
* @head: pointer
* @number: some int.
* Return: adress to n node
**/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nuevo_n;
	listint_t *a_n;
	int n = number;

	if (head == NULL)
	{
		return (NULL);
	}
	if (*head == NULL)
	{
		return (add_nodeint_end(head, n));
	}
	nuevo_n = malloc(sizeof(listint_t));
	if (nuevo_n  == NULL)
	{
		return (NULL);
	}

	nuevo_n->n = n;
	nuevo_n->next = NULL;

	a_n = *head;
	if (n <= a_n->n)
	{
		nuevo_n->next = a_n;
		*head = nuevo_n;
		return (nuevo_n);
	}
	while (1)
	{
		if (!a_n->next || a_n->next->n > n)
		{
			nuevo_n->next = a_n->next;
			a_n->next = nuevo_n;
			return (nuevo_n);
		}
		a_n = a_n->next;
	}
}
