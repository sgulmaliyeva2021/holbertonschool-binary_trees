#include "binary_trees.h"

/**
 * binary_tree_depth - Helper function to find depth of leftmost leaf
 * @tree: Pointer to the root node
 *
 * Return: Depth (number of edges from root to leftmost leaf)
 */
static size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_rec - Helper function to check if tree is perfect
 * @tree: Pointer to node
 * @depth: Depth of leaves
 * @level: Current level of node
 *
 * Return: 1 if perfect, 0 otherwise
 */
static int is_perfect_rec(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	/* Leaf node: check if at correct depth */
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	/* Node has only one child: not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Recur for left and right subtrees */
	return (is_perfect_rec(tree->left, depth, level + 1) &&
		is_perfect_rec(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = binary_tree_depth(tree);
	return (is_perfect_rec(tree, depth, 0));
}
