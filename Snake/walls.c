#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

    int xSnake[100], ySnake[100];
    int xOfFruit=0, yOfFruit=0;
    int snakeLen = 1;

int main()
{
    xSnake[0]=5;
    ySnake[0]=2;
    srand(time(NULL));
    while(xOfFruit<=0 || xOfFruit>=50 || yOfFruit<=0 ||yOfFruit>=25)
    {
        xOfFruit= rand()%50;
        yOfFruit= rand()%25;
    }

    draw:
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
            for(int k=0; k<snakeLen;k++)
            {
                if(j==0 || j==49)
                printf("*");
                else if (i==yOfFruit && j== xOfFruit)
                printf("o");
                else if(i==ySnake[k]&& j==xSnake[k])
                {
                    printf("o");
                }
                else
                printf(" ");
            }
        }
        printf("\n");
    }
}