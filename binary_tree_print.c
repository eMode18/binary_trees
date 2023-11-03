#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Recursively stores each level in an array of strings for printing.
 *
 * @tree: Pointer to the node to be printed
 * @offset: Offset for printing
 * @depth: Depth of the node
 * @s: Buffer for storing the tree structure
 *
 * Return: The length of the printed tree after the process.
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Calculates the height of a binary tree.
 *
 * @tree: Pointer to the node to calculate the height from.
 *
 * Return: The height of the tree starting at the specified node.
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	left_height = tree->left ? 1 + _height(tree->left) : 0;
	right_height = tree->right ? 1 + _height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_print - Prints a binary tree.
 *
 * @tree: Pointer to the root node of the tree to be printed.
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t tree_height, idx_i, idx_j;

	if (!tree)
		return;
	tree_height = _height(tree);
	s = malloc(sizeof(*s) * (tree_height + 1));
	if (!s)
		return;
	for (idx_i = 0; idx_i < tree_height + 1; idx_i++)
	{
		s[idx_i] = malloc(sizeof(**s) * 255);
		if (!s[idx_i])
			return;
		memset(s[idx_i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (idx_i = 0; idx_i < tree_height + 1; idx_i++)
	{
		for (idx_j = 254; idx_j > 1; --idx_j)
		{
			if (s[idx_i][idx_j] != ' ')
				break;
			s[idx_i][idx_j] = '\0';
		}
		printf("%s\n", s[idx_i]);
		free(s[idx_i]);
	}
	free(s);
}

/* Original code -  http://stackoverflow.com/a/13755911/5184480 */
