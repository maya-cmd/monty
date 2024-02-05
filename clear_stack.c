#include "monty.h"

/**
* clear_stack - Function frees a doubly linked list
* @head: head of the stack
*/
void clear_stack(stack_t *head)
{
        stack_t *temp_ptr;

        temp_ptr = head;
        while (head)
        {
                temp_ptr = head->next;
                free(head);
                head = temp_ptr;
       }
}
