#include "binary_trees.h"

/**
 * depth_of_node - Finds the depth of a node in a binary tree.
 * @node: Pointer to the node to find the depth of.
 *
 * Return: The depth of the node, or 0 if the node is NULL.
 */
size_t depth_of_node(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node && node->parent)
	{
		node = node->parent;
		depth++;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 * ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = depth_of_node(first);
	depth_second = depth_of_node(second);

	/* Move the pointer of the deeper node upwards to the same level */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	/* Move both pointers upwards until they meet at the common ancestor */
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}
