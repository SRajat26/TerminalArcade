#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int uchoice; 
    int a = rand();
    int cchoice=a%3+1;

    retry:
    printf("WELCOME TO ROCK PAPER SCISSORS\n");
    printf("Please choose: \n Rock:1\n Paper:2\n Scissor:3\n ");
    scanf("%d",&uchoice);
    if(uchoice<=0 || uchoice>3){
        printf("You entered an invalid input\n");
        goto retry;
    } 
    if (cchoice==uchoice)
    {
        printf("\n\nDraw\n");
    }
    else if (cchoice==1 && uchoice==2)
    {
        printf("\n\nYou Won!\n");
        printf("\n\nYou chose paper and computer chose rock\n");
    }
    else if (cchoice==1 && uchoice==3)
    {
        printf("\n\nYou Lost\n");
        printf("\n\nYou chose scissor and computer chose rock\n");
    }
    else if (cchoice==2 && uchoice==1)
    {
        printf("\n\nYou lost\n");
        printf("\n\nYou chose rock and computer chose paper\n");
    }
    else if (cchoice==2 && uchoice==3)
    {
        printf("\n\nYou won!\n");
        printf("\n\nYou chose scissor and computer chose paper\n");
    }
    else if (cchoice==3 && uchoice==1)
    {
        printf("\n\nYou won!\n");
        printf("\n\nYou chose rock and computer chose scissor\n");
    }
    else if (cchoice==3 && uchoice==2)
    {
        printf("\n\nYou lost\n");
        printf("\n\nYou chose paper and computer chose scissor\n");
    }
    return 0;
}
