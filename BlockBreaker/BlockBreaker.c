#include <stdio.h>
#include <windows.h>

int topWall= 0;
int bottomWall = 25;
int leftWall = 0;
int rightWall = 50;
int xblock[100];
int yblock[100];

void print();

int main()
{
    print();
}

void print()
{
    int k=1;
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
                printf("* ");
            else if(i<5 && j%2!=0)
            {
                    printf("#");
                    xblock[k]= j;
                    yblock[k]=i;
                    k++;
            }

            else
                printf(" ");
        }
        printf("\n");
    }
}