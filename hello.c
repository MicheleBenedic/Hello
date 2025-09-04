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
        printf("Hello World!\n");
    }
    else if (argc == 2)
    {
        // A single argument should be a name. Options like M/F are invalid here.
        if (strcmp(argv[1], "M") == 0 || strcmp(argv[1], "m") == 0 || strcmp(argv[1], "F") == 0 || strcmp(argv[1], "f") == 0)
        {
            fprintf(stderr, "Error: Missing name for option '%s'.\n", argv[1]);
            fprintf(stderr, "Use '%s --help' for usage instructions.\n", argv[0]);
            return 1;
        }
        printf("Hello %s!\n", argv[1]);
    }
    else if (argc == 3)
    {
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
            fprintf(stderr, "Error: Unrecognized option '%s'.\n", argv[1]);
            fprintf(stderr, "Use '%s --help' for usage instructions.\n", argv[0]);
            return 1;
        }
    }
    else
    {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        fprintf(stderr, "Use '%s --help' for usage instructions.\n", argv[0]);
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