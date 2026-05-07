// Name: Kayleb Cook
// Programming Assignment: Lab 4 - C Programming Warm-up

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

// define two functions so main can be defined first
int Parse(char* filename, char* outname, int count);
void ShowHelp();

int main(int argc, char** argv)
{
    int option;
    char* filename = "payroll.txt"; // set payroll.txt as the default
    char* outname  = NULL;
    int   count    = -1;

    while ((option = getopt(argc, argv, ":f:o:c:h")) != -1)
    {
        switch (option)
        {
            case 'f':
                filename = optarg; // if a filename is provided, overwrite the def filename
                break;
            case 'o':
                outname = optarg; // if an output file is provided, overwrite the def stdout
                break;
            case 'c':
                count = atoi(optarg); // if a count is provided, overwrite the def.
                break;
            case 'h':
                ShowHelp();
                return 0;
            case ':': // more cases to set to 
            case '?':
            default:
                ShowHelp();
                return 1;
        }
    }

    Parse(filename, outname, count);

    return 0;
}

// function to read from file 
int Parse(char* filename, char* outname, int count)
{
    FILE* FilePTR = fopen(filename, "r");
    if (FilePTR == NULL) 
    {
        printf("could not open file: %s\n", filename);
        return 0;
    }

    FILE* OutPTR = stdout;
    if (outname != NULL) 
    {
        OutPTR = fopen(outname, "w");
        if (OutPTR == NULL)
       	{
            printf("could not open output file: %s\n", outname);
            fclose(FilePTR);
            return 0;
        }
    }

    char first[16];
    char last[16];
    double hours;
    double rate;
    double pay;
    double total = 0.0;
    int limit = (count > 0 ) ? count : INT_MAX; // if count > 0, set limit to count; else, then set to max

    fprintf(OutPTR, "%-14s%-15s%8s %7s %9s\n",
            "First Name", "Last Name", "Hours", "Rate", "Total");

    for (int read = 0; read < limit && fscanf(FilePTR, " %15s %15s %lf %lf", first, last, &hours, &rate) == 4; read++)
    {
        pay = hours * rate;
        total += pay;
        fprintf(OutPTR, "%-14s%-15s%8.2f %7.2f %9.2f\n",
                first, last, hours, rate, pay);

    }

    fprintf(OutPTR, "Grand total %43.2f\n", total);

    fclose(FilePTR);
    if (OutPTR != stdout)
    {
	fclose(OutPTR);
    }

    return 0;
}

// function to display help message
void ShowHelp()
{
    printf("How to Use: \n"
           "-f to specify file name, but if not provided, will read from payroll.txt \n"
           "-o to specify name of output file, if not provided, will print using stdout \n"
           "-c to specify the number of records to read, if not provided, then all will be read \n"
           "-h to read all instructions again.\n");
}


