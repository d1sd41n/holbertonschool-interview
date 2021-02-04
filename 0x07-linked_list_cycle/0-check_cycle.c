#include "lists.h"

/**
 * check_cycle - doc
 * @list: doc
 *
 * Return: doc
 */
int check_cycle(listint_t *list)
{
	listint_t *c_data, *c_data_aux;

	if (!list)
		return (0);
	c_data = list;
	c_data_aux = list;
	while (c_data_aux->next && c_data_aux->next->next)
	{
		c_data = c_data->next;
		c_data_aux = c_data_aux->next->next;

		if (c_data == c_data_aux)
			return (1);
	}
	return (0);
}
