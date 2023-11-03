#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a node as the left child of another
 *                           node in a binary tree.
 * @parent: A pointer to the node where the left child is to be added.
 * @value: The value to be stored in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the newly added node.
 *
 * Description: If the parent node already has a left child, the new node
 *              takes its place and the old left child becomes the left
 *              child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *create_node;

	if (parent == NULL)
		return (NULL);

	create_node = binary_tree_node(parent, value);
	if (create_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		create_node->left = parent->left;
		parent->left->parent = create_node;
	}
	parent->left = create_node;

	return (create_node);
}

