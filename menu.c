#include<stdio.h>
int menu()
{
    int choice;
    printf("\nYou are in the Menu window! Please enter your choice!\n");
    printf("Press 1: Guess the cards!\n");
    input:
    scanf("%d", &choice);
    if(choice<=0)
    {
        printf("Invalid input, please try again");
        goto input;
    }
}