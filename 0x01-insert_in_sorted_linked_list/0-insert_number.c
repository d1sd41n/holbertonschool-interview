#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - docs
 * @head: docs
 * @number: tdocs
 * Return: docs
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nuevo_n;
	listint_t *act_n;

	act_n = *head;
	nuevo_n = malloc(sizeof(listint_t));
	if (nuevo_n == NULL)
		return (NULL);
	nuevo_n->next = NULL;
	nuevo_n->n = number;

	if (*head == NULL || (*head)->n >= nuevo_n->n)
	{
		nuevo_n->next = *head;
		*head = nuevo_n;
	}
	else
	{
		while (act_n->next != NULL && act_n->next->n < new->n)
		{
			act_n = act_n->next;
		}
		nuevo_n->next = act_n->next;
		act_n->next = nuevo_n;
	}
	return (nuevo_n);
}