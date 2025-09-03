#include <stdio.h>
#include <string.h>

void print_help(const char *program_name);
int main(int argc, char *argv[])
{
    // If the user asks for help, this has the highest priority
    if (argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0))
    {
        print_help(argv[0]);
        return 0;
    }

    if (argc == 1)
    {
        // Print "Hello World!" if there are no arguments
        printf("Hello World!\n");
    }

    else if (argc == 2)
    {
        printf("Hello %s!\n", argv[1]);
    }

    else if (argc == 3)
    {
        // Handle greeting with a title, accepting uppercase and lowercase
        if (strcmp(argv[1], "F") == 0 || strcmp(argv[1], "f") == 0)
        {
            printf("Greetings MS. %s! It's pleasant to meet you!\n", argv[2]);
        }
        else if (strcmp(argv[1], "M") == 0 || strcmp(argv[1], "m") == 0)
        {
            printf("Greetings MR. %s! It's pleasant to meet you!\n", argv[2]);
        }
        else
        {
            // If the first argument is invalid, greet the second one normally
            printf("Hello %s! (Option '%s' not recognized)\n", argv[2], argv[1]);
        }
    }

    else
    {
        printf("Invalid arguments. Use './hello --help' to see the instructions.\n");
        return 1;
    }

    return 0;
}

void print_help(const char *program_name)
{
    printf("Usage: %s [OPTION] [NAME]\n", program_name);
    printf("Greets a person in different ways.\n\n");
    printf("OPTIONS:\n");
    printf("  (none)\tGreets the provided name.\n");
    printf("  M | m\t\tAdds the title 'MR.' to the greeting.\n");
    printf("  F | f\t\tAdds the title 'MS.' to the greeting.\n");
    printf("  -h, --help\tShows this help message.\n\n");
    printf("EXAMPLES:\n");
    printf("  %s Michael\n", program_name);
    printf("  %s F Maria\n", program_name);
}