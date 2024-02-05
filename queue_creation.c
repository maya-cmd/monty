#include "monty.h"
/**
 * queue_creation - Function adds new  node to the queue.
 * @new_node: The new node being added.
 * @line_iterator: The opcode's line number
 */
void queue_creation(stack_t **new_node, __attribute__((unused))unsigned int line_iterator)
{
	stack_t *temp_node;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp_node = head;
	while (temp_node->next != NULL)
		temp_node = temp_node->next;

	temp_node->next = *new_node;
	(*new_node)->prev = temp_node;

}
