#include "monty.h"

/**
 * file_opening - Function to open the file
 * @file_title: The  name path of the file
 * Return: void
 *
 */
void file_opening(char *file)
{
        FILE *fd = fopen(file, "r");


        file_reading(fd);
        fclose(fd);
}

/**
 * file_reading - Accesses and reads contents of the file
 * @fd: The file descriptor's pointer
 * Return: void
 */
void file_reading(FILE *fd)
{
        int line_iterator = 1; 
	int opcode_format = 0;
        char *buffer = NULL;
        size_t line_length = 0;
	
	line_iterator = getline(&buffer, &line_length, fd);
        while (line_iterator != -1)
        {
                opcode_format = partition_line(buffer, line_iterator, opcode_format);
                line_iterator++;
        }
        free(buffer);
}

/**
 * partition_line - Function tokenizes line
 * @buffer: line from the file
 * @line_iterator: The line number
 * @opcode_format:  Holds information about mode of operation
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int partition_line(char *buffer, int line_iterator, int opcode_format)
{
        char *opcode, *argument;
        const char *partitioner = "\n ";

        if (buffer == NULL)
                fprintf(stderr, "Error: malloc failed\n");

        opcode = strtok(buffer, partitioner);
        if (opcode == NULL)
                return (opcode_format);
        argument = strtok(NULL, partitioner);

        if (strcmp(opcode, "stack") == 0)
                return (0);
        if (strcmp(opcode, "queue") == 0)
                return (1);

        function_finder(opcode, argument, line_iterator, opcode_format);
        return (opcode_format);
}

/**
 * function_finder - Finds the right function to use for the operation code
 * @operation_code: operation code used
 * @argument: argument of opcode
 * @opcode_format:  Format for storage
 * @line_iterator: Counts line
 * Return: void
 */
void function_finder(char *opcode, char *argument, int line_iterator, int opcode_format)
{
        int j = 0;
        int is_matched = 1;

        instruction_t opcode_list[] = {
                {"push", push_node},
                {"pall", print_stack},
                {"pint", print_top},
                {NULL, NULL}
        };

        if (opcode[0] == '#')
                return;

        while (opcode_list[j].opcode != NULL)
        {
                if (strcmp(opcode, opcode_list[j].opcode) == 0)
                {
                        handle_function(opcode_list[j].f, opcode, argument, line_iterator, opcode_format);
                        is_matched = 0;
                        break;
                }
                j++;
        }
        if (is_matched == 1)
                fprintf(stderr, "L%d: unknown instruction %s\n", line_iterator, opcode);
}

/**
 * handle_function - Function responsible for calling other functions
 * @func_ptr : Function pointer to the operation that is being called
 * @operation: string represention of the  operation.
 * @operand: The string representation of the value for the operation
 * @line_iterator: Counts lines
 * @opcode_format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void handle_function(op_handler handler, char *operation, char *argument, int line_iterator, int opcode_format)
{
        stack_t *node;
        int val_flag = 1;
        int j = 0;

        if (strcmp(operation, "push") == 0)
        {
                if (argument != NULL && argument[0] == '-')
                {
                        argument = argument + 1;
                        val_flag = -1;
                }
                if (argument == NULL)
                        fprintf(stderr, "L%d: usage: push integer\n", line_iterator);
                while(argument[j] != '\0')
                {
                        if (isdigit(argument[j]) == 0)
                                 fprintf(stderr, "L%d: usage: push integer\n", line_iterator);
                }
		node = node_creation(atoi(argument) * val_flag);
                if (opcode_format == 0)
                        handler(&node, line_iterator);
		if (opcode_format == 1)
			queue_creation(&node, line_iterator);
        }
        else
                handler(&head, line_iterator);
}
