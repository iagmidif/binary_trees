#include "binary_trees.h"


/**
 * binary_trees_ancestor - a function that finds
 * the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	binary_tree_t *first_cp, *second_cp;

	if (!first || !second)
		return (NULL);

	first_cp = (binary_tree_t *)first;
	second_cp = (binary_tree_t *)second;
	while (first_cp)
	{
		while (second_cp)
		{
			if (first_cp == second_cp)
				return (first_cp);
			second_cp = second_cp->parent;
		}
		second_cp = (binary_tree_t *)second;
		first_cp = first_cp->parent;
	}

	return (NULL);
}
