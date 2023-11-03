#include "binary_trees.h"

/**
 * binary_tree_node - Generates a node for a binary tree.
 * @parent: A pointer to the parent node.
 * @value: The value to be assigned to the new node.
 *
 * Return:  NULL on error
 *         Otherwise - a pointer to the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *generate_node;

	generate_node = malloc(sizeof(binary_tree_t));
	if (generate_node == NULL)
		return (NULL);

	generate_node->n = value;
	generate_node->parent = parent;
	generate_node->left = NULL;
	generate_node->right = NULL;

	return (generate_node);
}
