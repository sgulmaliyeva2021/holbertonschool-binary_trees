#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling of
 *
 * Return: Pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is left child and right child exists, return right */
	if (node->parent->left == node && node->parent->right != NULL)
		return (node->parent->right);

	/* If node is right child and left child exists, return left */
	if (node->parent->right == node && node->parent->left != NULL)
		return (node->parent->left);

	/* Node has no sibling */
	return (NULL);
}
