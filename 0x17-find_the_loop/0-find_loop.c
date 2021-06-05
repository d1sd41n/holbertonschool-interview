#include "lists.h"

/**
 * loop_located - doc
 * @head: doc
 * @helper: doc
 * Return: doc
 */
listint_t *loop_located(listint_t *head, listint_t *helper)
{
	while (head != helper)
	{
		head = head->next;
		helper = helper->next;
	}
	return (head);
}

/**
 * find_listint_loop - doc
 * @head: doc
 * Return: doc
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *second;

	if (!head)
		return (0);

	first = head->next;
	second = head->next->next;
	while (first && second && second->next)
	{
		first = first->next;
		second = second->next->next;
		if (first == second)
			return (loop_located(head, second));
	}
	return (0);
}
