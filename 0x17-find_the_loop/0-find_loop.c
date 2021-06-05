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
	listint_t *f_s, *second;

	if (!head)
		return (0);

	f_s = head->next;
	second = head->next->next;

	while (f_s && second && second->next)
	{
		f_s = f_s->next;
		second = second->next->next;
	
		if (f_s == second)
			return (loop_located(head, second));

	}

	return (0);
}
