#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_leftmost_depth - function that measures the depth
 * of the leftmost leaf of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 *
 * Return: the depth of the leftmost leaf of the tree
 */
int binary_tree_leftmost_depth(binary_tree_t *tree)
{
	int h = 0;

	while (tree)
	{
		h++;
		tree = tree->left;
	}

	return (h);
}


/**
 * binary_tree_is_perfect_wrapper - helper function for binary_tree_is_perfect
 * @tree: posize_ter to the root node of the tree to check
 * @h: depth of the leftmost leaf of the tree
 * @d: depth of tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_wrapper(const binary_tree_t *tree, int h, int d)
{
	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (h == d + 1);

	if (!(tree->left) || !(tree->right))
		return (0);

	return (binary_tree_is_perfect_wrapper(tree->left, h, d + 1) &&
			binary_tree_is_perfect_wrapper(tree->right, h, d + 1));
}


/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: posize_ter to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *node = (binary_tree_t *)tree;

	return (binary_tree_is_perfect_wrapper(tree,
				binary_tree_leftmost_depth(node), 0));
}
