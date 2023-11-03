#include "binary_trees.h"

/**
 * binary_tree_insert_right - Adds a node as the right child of another
 *                            node in a binary tree.
 * @parent: A pointer to the node where the right child is to be added.
 * @value: The value to be stored in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the newly added node.
 *
 * Description: If the parent node already has a right child, the new node
 *              takes its place and the old right child becomes the right
 *              child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *create_node;

	if (parent == NULL)
		return (NULL);

	create_node = binary_tree_node(parent, value);
	if (create_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		create_node->right = parent->right;
		parent->right->parent = create_node;
	}
	parent->right = create_node;

	return (create_node);
}

