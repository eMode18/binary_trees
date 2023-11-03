#include "binary_trees.h"

/**
 * binary_tree_sibling - Identifies the sibling of a specific
 * node in a binary tree.
 * @node: A pointer to the targeted node for finding its sibling.
 *
 * Return: If the specified node is NULL or has no sibling, the function
 * returns NULL.
 *         Otherwise, it returns a pointer pointing to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}

