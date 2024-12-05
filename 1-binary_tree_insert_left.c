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
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
		parent->left->parent = new_node;

	parent->left = new_node;

	return (parent->left);
}
