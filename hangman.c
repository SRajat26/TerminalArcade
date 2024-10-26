#include <stdio.h>
#include <string.h>

int main()
{
    // taking word from player 1
    char word[50];
    printf("Enter the word(s): ");
    gets(word);

    int len = strlen(word);

    printf("\033[2J\033[1;1H"); // clear the terminal

    // array for displaying after every guess
    char new_word[50];
    new_word[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        if (word[i] == ' ')
        {
            new_word[i] = ' ';
        }
        else
        {
            new_word[i] = '_';
        }
    }

    printf("\n\t\t%s\n\n", new_word);

    int score = 0;
    int lifes = 7;
    while (lifes != 0)
    {
        char guess;
        printf("Guess the letter of the word: ");
        scanf(" %c", &guess);
        int correct = 0;

        for (int i = 0; i < len; i++)
        {
            if (word[i] == guess)
            {
                score++;
                correct = 1;
                new_word[i] = guess;
            }
        }
        if (correct == 0)
        {
            lifes--;
            printf("Wrong guess!, chances left = %d\n", lifes);
        }
        printf("\t%s\n", new_word);
        if (strcmp(word, new_word) == 0)
        {
            printf("Congratulations you guessed the word!");
            break;
        }
    }
    if (lifes == 0)
    {
        printf("You are not able to guess the word\n");
        printf("the word(s) is: %s\n", word);
    }
    if (lifes == 7)
    {
        score += 10;
    }
    else
    {
        score += lifes;
    }
    printf("Your Score is: %d", score);

    return 0;
}