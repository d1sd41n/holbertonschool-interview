#include "binary_trees.h"


/**
* sorted_array_to_avl - doc
* @array: doc
* @size: doc
* Return: doc
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *tree = NULL;

if (array == NULL || size == 0)
return (NULL);

add_middle_value(&tree, array, 0, (int) size - 1);

return (tree);
}

/**
* add_middle_value - doc
*
* @tree: - doc
* @array: doc
* @idx_l: doc.
* @idx_r: doc
* Return: doc
*/

avl_t *add_middle_value(avl_t **tree, int *array, int idx_l, int idx_r)
{
int value = 0;
size_t value_idx = 0;
avl_t *node = NULL;

if (tree == NULL || idx_r < idx_l)
return (NULL);

value_idx = (idx_r  - idx_l) / 2 + idx_l;
value = array[value_idx];

node = binary_tree_node(NULL, value);
if (node == NULL)
return (NULL);
if (*tree == NULL)
*tree = node;

node->left = add_middle_value(tree, array, idx_l, value_idx - 1);
if (node->left != NULL)
(node->left)->parent = node;
node->right = add_middle_value(tree, array, value_idx + 1, idx_r);
if (node->right != NULL)
(node->right)->parent = node;

return (node);
}





/**
* binary_tree_node - doc
* @parent: doc
* @value: doc
* Return: doc
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node = NULL;

node = malloc(sizeof(binary_tree_t));
if (node == NULL)
return (NULL);
node->n = value;
node->parent = parent;
node->left = NULL;
node->right = NULL;

return (node);
}
