#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: Pointer to the root node of the tree to count the leaves.
 *
 * Return: The number of leaves. If tree is NULL, return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t s;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	s = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (s);
}
