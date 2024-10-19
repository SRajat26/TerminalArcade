#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int guessTheCard()
{
    printf("Game instructions: \n");
    printf("You have 3 cards, a king (K), queen (Q) and a joker(10). The computer randomly shuffles these cards and you need to guess the correct order.\n");
    printf("Please enter your gues in the form of alphabets only.\n");
    printf("For example, to guess King, Queen and Joker, write KQJ\n");
    char cards[4]= "KQJ";
    int attempts=0;
    srand(time(NULL));   // Initialization, should only be called once.
    for(int i=0; i<5; i++)
    {
        int index_1= rand()%3;
        int index_2= rand()%3;
        char temp = cards[index_1];
        cards[index_1]= cards[index_2];
        cards[index_2]= temp;
    }
    retry:
    printf("Please enter your guessed order: \t");
    char guess[4];
    gets(guess);
    if(strlen(guess)>3)
    {
        printf("Input string is too long, please try again\n");
        attempts++;
        goto retry;
    }
    //test to see if all the characters are KQJ
    //compare the strings
    //give output and option to retry
    //points system according to number of attempts
}