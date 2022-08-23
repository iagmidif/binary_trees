#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *current = malloc(sizeof(binary_tree_t));

	current->n = value;
	current->parent = parent;
	current->left = NULL;
	current->right = NULL;

	return (current);
}
