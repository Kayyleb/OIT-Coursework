://**********************************************************
//
// Code that demonstrates use of getopt()
//
// Author: Phil Howard
//

// The following include file declares getopt and its corresponding variables
#include <unistd.h>

//*********************************************************
int main(int argc, char **argv)
{
    int option;

    // Syntax note: the form "(a=b) != c" means to perform the assignment a=b
    // and evaluate to true if the assigned value (in this case b) is not 
    // equal to c. Include the parenthesis to ensure correct behavior and to 
    // potentially avoid a compiler warning.
    //
    // The third argument to getopt is a string that lists the valid options.
    // The leading ":" means that getopt won't print an error message if an 
    // invalid option is specified (you will do that yourself)
    // The options are single characters. 
    // If the option takes a parameter, the character must be followed by a :
    //
    // The valid options in this example are the characters h, o, and z.
    // The o option requires a parameter.
    while ( (option=getopt(argc, argv, ":ho:z")) != -1)
    {
        switch (option)
        {
            case 'h':
                // The following function should print a help message that
                // explains the valid options. It should then call exit() to
                // terminate the program
                print_help();
                break;
            case 'o':
                // optarg is a char* pointing to the specified parameter.
                // The variable is assigned by the call to getopt()
                strcpy(output_name, optarg);
                break;
            case 'z':
                // handle whatever the 'z' option does
                break;
            default:
                // User specified an invalid option, so print the help
                // message and exit.
                print_help();
                break;
        }
    }

    return 0;
}
