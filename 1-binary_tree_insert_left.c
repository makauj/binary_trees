#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a left child node
 * @parent: pointer to the parent node
 * @value: the value to store in new node
 *
 * Return: pointer to new node, else NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	if (!parent)
		return (NULL);

	left_child = binary_tree_node(parent, value);
	if (!left_child)
		return (NULL);

	if (parent->left != NULL)
		parent->left->parent = left_child;

	parent->left = left_child;

	return (left_child);
}
