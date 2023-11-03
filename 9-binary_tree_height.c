#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer to the main node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0;
 * otherwise, it returns the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t h_left = 0, h_right = 0;

		h_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		h_right = tree->right ? 1 +
				binary_tree_height(tree->right) : 0;
		return ((h_left > h_right) ? h_left : h_right);
	}
	return (0);
}

