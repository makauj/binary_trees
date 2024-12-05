#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child
 * @parent: Pointer to the parent node.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	right_child = binary_tree_node(parent, value);
	if (!parent || !right_child)
		return (NULL);

	if (parent->right != NULL)
		parent->right->parent = right_child;

	parent->right = right_child;

	return (right_child);
}
