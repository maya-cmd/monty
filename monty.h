#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>


typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef struct container_s
{
        char *arg;
        FILE *file;
        char *args_present;
        int lifo;
}  container_t;
extern container_t container;

typedef void (*op_handler)(stack_t **, unsigned int);
extern stack_t *head;

void file_opening(char *file_title);
void file_reading(FILE *fd);
int partition_line(char *buffer, int line_number, int format);
void function_finder(char *operation_code, char *argument, int line_iterator, int opcode_format);
void handle_function(op_handler handler, char *operation, char *argument, int line_iterator, int opcode_format);
void clear_stack(stack_t *head);
void print_stack(stack_t **stack_head, unsigned int line_number);
void print_top(stack_t **stack_head, unsigned int line_number);
void push_node(stack_t **head, unsigned int counter);
#endif