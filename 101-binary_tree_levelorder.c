#include "binary_trees.h"


/**
 * tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t lHeight, rHeight;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);

	lHeight = tree_height(tree->left);
	rHeight = tree_height(tree->right);

	if (lHeight > rHeight)
		return (lHeight + 1);
	return (rHeight + 1);
}


/**
 * traverse_levelorder - traverse a specific level of a binary tree
 * @tree: pointer to the root node of the tree to travese
 * @func: pointer to a function to call for each node on the specified node
 * @level: level to be traversed
 *
 * Return: nth, void
 */
void traverse_levelorder(binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		traverse_levelorder(tree->left, func, level - 1);
		traverse_levelorder(tree->right, func, level - 1);
	}
}


/**
 * binary_tree_levelorder - function that goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Return: nth, void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = tree_height(tree) + 1, i;
	binary_tree_t *root = (binary_tree_t *)tree;

	for (i = 1; i <= height; i++)
		traverse_levelorder(root, func, i);
}
