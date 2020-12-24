#include "binary_trees.h"

void d_head(heap_t **root, heap_t **new_node);
void aux_process(heap_t *ca, heap_t **r, int aux_var1, int aux_var2);
void altura_de_pila(heap_t *aux_var_2, int *aux_var);


/**
 * heap_insert - docs
 * @root: docs
 * @value: docs
 * Return: docs
 */

heap_t *heap_insert(heap_t **root, int value)
{
	int aux = 0;
	heap_t *nn = NULL, *padre = NULL;

	if (!root)
	{
		return (NULL);
	}

	nn = binary_tree_node(NULL, value);

	if (!*root)
	{
		*root = nn;
		return (nn);
	}

	altura_de_pila(*root, &aux);

	if (aux >= 2)
	{
		aux_process(*root, &padre, aux, 0);
	}
	else

	{
		padre = *root;
	}

	if (!padre)
	{
		padre = *root;
		while (padre->left != NULL)
			padre = padre->left;
	}

	if (!padre->left)
	{
		padre->left = nn;
		nn->parent = padre;
	}

	else
	{
		padre->right = nn;
		nn->parent = padre;


	}
	d_head(root, &nn);
	return (nn);
}

/**
 * d_head - docs
 * @last: docs
 * @new_node: docs
 */

void d_head(heap_t **last, heap_t **new_node)
{
	int nodo_padre = 0;

	if (!(*new_node)->parent)
	{
		*last = *new_node;
		return;
	}

	else if ((*new_node)->n >
		((*new_node)->parent)->n)
	{
		nodo_padre = (*new_node)->parent->n;

		(*new_node)->parent->n = (*new_node)->n;
		(*new_node)->n = nodo_padre;
		*new_node = (*new_node)->parent;
		d_head(last, new_node);
	}
}

/**
 * altura_de_pila - docs
 * @aux_var_2: docs
 * @aux_var: docs
 */

void altura_de_pila(heap_t *aux_var_2, int *aux_var)
{
	*aux_var += 1;
	if (aux_var_2->left)
	{
		altura_de_pila(aux_var_2->left, aux_var);
	}
}

/**
 * aux_process - docs
 * @ca: docs
 * @r: docs
 * @aux_var1: docs
 * @height: docs
 */

void aux_process(heap_t *ca, heap_t **r, int aux_var1,
		 int aux_var2)
{
	aux_var2 += 1;
	if ((aux_var1 - 1) == aux_var2)
	{
		if (!ca->left || !ca->right)
		{


			*r = ca;
		}

		return;
	}

	if (ca->left)
	{
		aux_process(ca->left, r, aux_var1, aux_var2);
	}

	if (!(*r) && (ca->right))
	{
		aux_process(ca->right, r, aux_var1, aux_var2);
	}
}
