#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a node is the root of a binary tree
 * @node: Pointer to the node
 *
 * Return: 1 if root, 0 if not or node is NULL
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}
