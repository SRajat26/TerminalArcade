#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>


int main()
{
    char files[2][100] = {"madlib1.txt", "madlib2.txt"};
    char input[2][100] = {"input1.txt", "input2.txt"};

    FILE *mad;
    FILE *input_mad;

    // random story choosing
    srand(time(NULL));
    int a = rand()%2;

    // opening files
    mad = fopen(files[a], "r");
    input_mad = fopen(input[a], "r");

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

    // taking input
    char user_input[50][100];
    for (int i = 0; i < 50; i++)
    {
        char c = 'a';
        printf("%d. ", i+1);
        while(c != '\n'){
            c = getc(input_mad);
            printf("%c", c);
            if(c == EOF){
                printf("\n");
                break;
            }
        }
        fgets(user_input[i], 100, stdin);
        int len = strlen(user_input[i]);
        user_input[i][len-1] = '\0';
        printf("\n");

        if(c == EOF){
            break;
        }

    }

    // storing story file data
    char story_data[1000];
    int i = 0;
    while (1)
    {
        char ch = fgetc(mad);
        if (ch == EOF)
        {
            break;
        }
        else if (ch == '_')
        {
            printf("%s", user_input[i]);
            i++;
        }
        else
        {
            printf("%c", ch);
        }
    }

    // closing files
    fclose(mad);
    fclose(input_mad);

    // printing story
    printf("%s", story_data);

    return 0;
}