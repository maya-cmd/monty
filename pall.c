#include "monty.h"

/**
 * print_stack - prints the elements of the stack
 * @stack_head: pointer to the head of the stack
 * @line_number: line number (not used)
 * Return: void
 */
void print_stack(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    (void)line_number;

    current_node = *stack_head;
    if (current_node == NULL)
        return;
    
    while (current_node != NULL)
    {
        printf("%d\n", current_node->data);
        current_node = current_node->next;
    }
}
