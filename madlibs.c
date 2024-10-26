#include <stdio.h>
#include <stdlib.h>

int main()
{
    char files[2][100] = {"madlib1.txt", "madlib2.txt"};
    char input[2][100] = {"input1.txt", "input2.txt"};

    FILE *mad;
    FILE *input_mad;

    // opening files
    mad = fopen(files[0], "r");
    input_mad = fopen(input[0], "r");

    // error handling
    if (input_mad == NULL)
    {
        printf("The file is not opened, ERROR 101");
        exit(0);
    }
    if (mad == NULL)
    {
        printf("The file is not opened, ERROR 101");
        exit(0);
    }

    // storing input file data
    char input_data[50][100];
    int j = 0;

    while (fgets(input_data[j], 500, input_mad) != NULL)
    {
        j++;
    }

    // taking input
    int user_input[50];
    for (int i = 0; i < j; i++)
    {
        printf("%d. %s", i + 1, input_data[i]);
        scanf("%s", &user_input[i]);
        printf("\n");
    }

    // storing story file data
    char story_data[1000];
    int c = 0, i = 0;
    while (1)
    {
        char ch = fgetc(mad);
        if (ch == EOF)
        {
            break;
        }
        else if (ch == '_')
        {
            story_data[c++] = user_input[i++];
        }
        else if (ch == '\n')
        {
            continue;
        }
        else
        {
            story_data[c] = ch;
            c++;
        }
    }

    // closing files
    fclose(mad);
    fclose(input_mad);

    // printing story
    printf("%s", story_data);

    return 0;
}