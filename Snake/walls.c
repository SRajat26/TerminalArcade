#include<time.h>
#include <stdlib.h>
#include<stdio.h>
int main()
{
    int xOfFruit=0, yOfFruit=0;
    srand(time(NULL));
    while(xOfFruit<=0 || xOfFruit>=50 || yOfFruit<=0 ||yOfFruit>=25)
    {
        xOfFruit= rand()%50;
        yOfFruit= rand()%25;
    }
    printf("Position of fruit = %d %d", xOfFruit, yOfFruit);


    for(int i=0; i<25; i++)
    {
        //top and bottom walls
        if(i==0 || i==24)
        {
            for(int j=0;j<25; j++) 
            printf("* ");
        }
        else
        for(int j=0;j<50; j++)  //left and right walls
        {
            if(j==0 || j==49)
            printf("*");
            else if (i==yOfFruit && j== xOfFruit)
            printf("o");
            else
            printf(" ");
        }
        printf("\n");
    }
}