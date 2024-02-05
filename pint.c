#include "monty.h"

/**
 * print_top - prints the top element of the stack
 * @stack_head: pointer to the head of the stack
 * @line_iterator line number
 * Return: void
 */
void print_top(stack_t **stack_head, unsigned int line_iterator)
{
    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%u: can't print top, stack empty\n", line_iterator);
        fclose(container.file);
        free(container.args_present);
        clear_stack(*stack_head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack_head)->n);
}

