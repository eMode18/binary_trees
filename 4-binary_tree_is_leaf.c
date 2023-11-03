#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Verifies if a node is a leaf in a binary tree.
 * @node: A pointer to the node to verify.
 *
 * Return: 1 if the node is indeed a leaf.
 *         else, return - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}

