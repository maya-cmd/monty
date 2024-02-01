#include "monty.h"

/**
 * push_node - adds a node to the stack
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: void
 */
void push_node(stack_t **head, unsigned int counter)
{
    int num, i = 0, flag = 0;

    if (bus.command_arg)
    {
        if (bus.command_arg[0] == '-')
            i++;
        for (; bus.command_arg[i] != '\0'; i++)
        {
            if (bus.command_arg[i] > 57 || bus.command_arg[i] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    num = atoi(bus.command_arg);
    if (bus.lifo == 0)
        add_node_to_stack(head, num);
    else
        add_node_to_queue(head, num);
}

