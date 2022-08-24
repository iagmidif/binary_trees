#include "binary_trees.h"


/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lHeight, rHeight;

	if (!tree)
		return (0);

	lHeight = binary_tree_height(tree->left);
	rHeight = binary_tree_height(tree->right);

	if (lHeight > rHeight)
		return (lHeight + 1);
	return (rHeight + 1);
}

/**
 * binary_tree_balance - function that measures
 * the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of a binary tree,
 * left subtree - right subtree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
