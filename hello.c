#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // If the user asks for help, this has the highest priority
    if (argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0))
    {
        printf("Usage: ./hello [OPTION] [NAME]\n");
        printf("Greets a person in different ways.\n\n");
        printf("OPTIONS:\n");
        printf("  (none)\tGreets the provided name.\n");
        printf("  M | m\t\tAdds the title 'MR.' to the greeting.\n");
        printf("  F | f\t\tAdds the title 'MS.' to the greeting.\n");
        printf("  -h, --help\tShows this help message.\n\n");
        printf("EXAMPLES:\n");
        printf("  ./hello Michele\n");
        printf("  ./hello F Maria\n");
        return 0; // Exits the program after showing the help message
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