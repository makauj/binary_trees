#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right)
		new_root->right->parent = tree;

	new_root->right = tree;
	new_root->parent = tree->parent;

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}

	tree->parent = new_root;

	return (new_root);
}
