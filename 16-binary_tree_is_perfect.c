#include "binary_trees.h"

unsigned char check_if_leaf(const binary_tree_t *node);
size_t compute_depth(const binary_tree_t *tree);
const binary_tree_t *find_leaf(const binary_tree_t *tree);
int check_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * check_if_leaf - Verifies if a node is a leaf in a binary tree.
 * @node: A pointer to the node to verify.
 *
 * Return: Returns 1 if the node is a leaf; otherwise, returns 0.
 */
unsigned char check_if_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * compute_depth - Computes the depth of a specified node in a binary tree.
 * @tree: A pointer to the node to calculate the depth of.
 *
 * Return: Returns the depth of the node.
 */
size_t compute_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + compute_depth(tree->parent) : 0);
}

/**
 * find_leaf - Retrieves a leaf node from a binary tree.
 * @tree: A pointer to the root node of the tree to search for a leaf in.
 *
 * Return: Returns a pointer to the first encountered leaf node.
 */
const binary_tree_t *find_leaf(const binary_tree_t *tree)
{
	if (check_if_leaf(tree) == 1)
		return (tree);
	return (tree->left ? find_leaf(tree->left) : find_leaf(tree->right));
}

/**
 * check_perfect_recursive - Recursively checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of a leaf node in the binary tree.
 * @level: The current level of the node.
 *
 * Return: Returns 1 if the tree is perfect; otherwise, returns 0.
 */
int check_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (check_if_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		check_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Determines if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to examine.
 *
 * Return: Returns 0 if the tree is NULL or not perfect. Otherwise, returns 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_perfect_recursive(tree, compute_depth(find_leaf(tree)), 0));
}

