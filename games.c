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
    int attempts=0, i;
    srand(time(NULL));   // Initialization, should only be called once.
    for(int i=0; i<5; i++)
    {
        int index_1= rand()%3;
        int index_2= rand()%3;
        char temp = cards[index_1];
        cards[index_1]= cards[index_2];
        cards[index_2]= temp;
    }
    char guess[4];
    retry:
    printf("Please enter your guessed order: \t");
    scanf("%s",&guess);
    if(strlen(guess)>3 && ++attempts>3)
    {
        printf("Input string is too long, please try again\n");
        goto retry;
    }
    //test to see if all the characters are KQJ
    for (i=0; i<3; i++)
    {
        int freq_k, freq_q, freq_j;
        freq_k=freq_q=freq_j=0;
        if(cards[i]=='K' && freq_k==0)
        freq_k++;
        else if(cards[i]=='Q' && freq_q==0)
        freq_q++;
        else if(cards[i]=='J' && freq_j==0)
        freq_j++;
        else
        {
            printf("Input String contains invalid characters, please try again\n");
            attempts++;
            goto retry;
        }
    }
    //compare the strings
    for (i=0; i<4; i++)
    {
        char guess_ch= guess[i];
        char cards_ch= cards[i];
        if(guess_ch != cards_ch && attempts<=3)
        {
        printf("You guessed wrong! Want to retry? Press 1 for yes and any other character for No\n");
        attempts++;
        char rtry;
        fflush(stdin); 
        scanf("%c",rtry);
        if(rtry!='1')
        goto end_cards;
        else 
        goto retry;
        }
        if(attempts>3)
        {
            printf("3 wrong guesses! Game Over\n");
            goto end_cards;
        }
    }
    if(i==4)
    printf("CONGRATS! You guess right in %d attempts.\n",attempts);
    end_cards:
    printf("The correct order of cards was:\t%s\n",cards);
    switch(attempts)
    {
        case 1:
        printf("You earned 5 points!");
        return 5;
        case 2:
        printf("You earned 3 points!");
        return 3;
        case 3:
        printf("You earned 1 point!");
        return 1;
        default:
        printf("No points earned. Game Over!\n");
        return 0;
    }
    //refactor
}