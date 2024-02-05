#include "monty.h"

int main(int argc, char *argv[])
{

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        file_opening(argv[1]);
        
        clear_stack(head);
        
        return (0);
}
