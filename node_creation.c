#include "monty.h"

/**
 * node_creation - Function that creates and addss a node.
 * @n: The value to be used
 * Return: A pointer to the node if it's successful. Otherwise NULL.
 */
stack_t *node_creation(int n)
{
        stack_t *node;

        node = malloc(sizeof(stack_t));
        if (node == NULL)
                fprintf(stderr, "Error: malloc failed\n");
        node->next = NULL;
        node->prev = NULL;
        node->n = n;
	return(node);
}
