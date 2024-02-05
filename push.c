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

    if (container.arg)
    {
        if (container.arg[0] == '-')
            i++;
        for (; container.arg[i] != '\0'; i++)
        {
            if (container.arg[i] > 57 || container.arg[i] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(container.file);
            free(container.args_present);
            clear_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(container.file);
        free(container.args_present);
        clear_stack(*head);
        exit(EXIT_FAILURE);
    }
    num = atoi(container.arg);
    if (container.lifo == 0)
        node_creation(num);
    else
        queue_creation(head, num);
}

