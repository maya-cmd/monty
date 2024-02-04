#include "monty.h"

int main(int argc, char *argv[])
{
        FILE *file;
        size_t size = 0;
        ssize_t retrieve_line = 1;
        stack_t *stack = NULL;
        unsigned int counter = 0;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        file_opening(argv[1]);
        
        clear_stack(stack);
        
        return (0);
}
