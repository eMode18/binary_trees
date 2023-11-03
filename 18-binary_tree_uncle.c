#include "binary_trees.h"

/**
 * binary_tree_uncle - Determines the uncle of a specific
 * node within a binary tree.
 * @node: A pointer indicating the node for which the uncle is to be found.
 *
 * Return: Returns NULL if the node is NULL or has no uncle.
 *         Otherwise, it returns a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}

