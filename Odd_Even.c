#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int check()
{ // check each user input
    int n;
    scanf("%d", &n);

    if (n > 10 || n < 1)
    {
        printf("Enter a valid input.\n");
        check(n);
    }
    else
    {
        return n;
    }
}

int C_score()
{ // give computer input
    srand(time(NULL));
    int score = (rand() % 10) + 1;

    return score;
}

int batting(int n, int bat)
{
    int score = 0;
    while (1)
    {
        printf("Enter your runs(1-10): ");

        int runs = check();
        int c_runs = C_score();

        if (bat)
        {
            score += runs;
        }
        else
        {
            score += c_runs;
        }

        if (runs == c_runs)
        {
            printf("Out!\n");
            if (bat)
            {
                score -= runs;
            }
            else
            {
                score -= c_runs;
            }
            printf("Total runs: %d\n", score);
            break;
        }
        else if (score > n)
        {
            break;
        }
        else
        {
            printf("Total runs: %d\n", score);
        }
    }
    return score;
}

int bowling(int n, int bat)
{
    int score = 0;
    while (1)
    {
        printf("Enter your runs(1-10): ");

        int runs = check();
        int c_runs = C_score();

        if (bat)
        {
            score += c_runs;
        }
        else
        {
            score += runs;
        }

        if (runs == c_runs)
        {
            printf("Out!\n");
            if (bat)
            {
                score -= c_runs;
            }
            else
            {
                score -= runs;
            }
            printf("Total runs: %d\n", score);
            break;
        }
        else if (score > n)
        {
            break;
        }
        else
        {
            printf("Total runs: %d\n", score);
        }
    }
    return score;
}

int main()
{
    char player[50];
    printf("Enter your name: ");
    scanf("%[^\n]s", player);

    char choice;
    printf("%s, input 'o' for odd and 'e' for even. :- ", player);

    while (1)
    {
        scanf(" %c", &choice);
        if (choice == 'o' || choice == 'e')
        {
            break;
        }
        else
        {
            printf("Enter a valid input. :-");
        }
    }

    printf("%s, input a no. between 1-10 : ", player);
    int num1 = check();

    int num2 = C_score();

    int bowl;

    if ((num1 + num2) % 2 == 0)
    {
        if (choice == 'e')
        {
            printf("You won!\nchoose 'B' to bat or 'b' to bowl: ");
            scanf(" %c", &choice);
        }
        if (choice == 'o')
        {
            printf("You lost!\n");

            srand(time(NULL));
            bowl = rand() % 2;

            if (bowl == 0)
            {
                printf("Computer chooses to bat\n");
            }
            else
            {
                printf("Computer chooses to bowl\n");
            }
        }
    }
    else
    {
        if (choice == 'o')
        {
            printf("You won the toss!\nchoose 'B' to bat or 'b' to bowl: ");
            scanf(" %c", &choice);
        }
        if (choice == 'e')
        {
            printf("You lost the toss!\n");

            srand(time(NULL));
            bowl = rand() % 2;

            if (bowl == 0)
            {
                printf("Computer chooses to bat\n");
            }
            else
            {
                printf("Computer chooses to bowl\n");
            }
        }
    }

    int p_score;
    int c_score;

    if (choice == 'B' || bowl == 1)
    {
        printf("You are batting and computer is bowling\n");
        p_score = batting(100000, 1);
        printf("Now, You are bowling and computer is batting\n");
        c_score = bowling(p_score, 1);
    }
    else if (choice == 'b' || bowl == 0)
    {
        printf("You are bowling and computer is batting\n");
        c_score = batting(100000, 0);
        printf("Now, You are batting and computer is bowling\n");
        p_score = bowling(c_score, 0);
    }

    int score = p_score;
    if (p_score > c_score)
    {
        printf("\nYou won!");
    }
    else if (p_score == c_score)
    {
        printf("\nThe game is tied");
    }
    else
    {
        printf("\nYou lost!");
    }

    return 0;
}