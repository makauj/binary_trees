#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ?
				left_height : right_height));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect using recursion.
 * @tree: Pointer to the current node.
 * @depth: The depth of the current node.
 * @h: The height of the tree.
 *
 * Return: 1 if the tree is perfect, 0 if not.
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t h)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (depth == h);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_recursive(tree->left, depth + 1, h) &&
			is_perfect_recursive(tree->right, depth + 1, h));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 if not. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	return (is_perfect_recursive(tree, 0, height));
}
