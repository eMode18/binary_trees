#include "binary_trees.h"

/**
 * binary_tree_balance - Determines the balance factor of a binary tree.
 * @tree: A pointer to the main node of the tree for calculating
 * the balance factor.
 *
 * Return: If the tree is NULL, the function returns 0;
 * otherwise, it returns the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Computes the height of a binary tree.
 * @tree: A pointer to the main node of the tree for calculating the height.
 *
 * Return: If the tree is NULL, the function returns 0; otherwise, it returns
 * the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t h_left = 0, h_right = 0;

		h_left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		h_right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((h_left > h_right) ? h_left : h_right);
	}
	return (0);
}

