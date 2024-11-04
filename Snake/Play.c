#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
//This is the only function that will print anything to cocnsole

int gameOver= 0;

int xHead= 5;
int yHead= 5;

int xSnake[100];
int ySnake[100];
int snakeLen = 3;

int xFruit;
int yFruit;

int CoordFlag=1;

void spawnFruit()
{
    srand(time(NULL));
    while(xFruit<=0 || xFruit>=50 || yFruit<=0 ||yFruit>=25)
    {
        xFruit= rand()%50;
        yFruit= rand()%25;
    }
}

void draw()
{
    system("cls");
    for(int y =0; y<25; y++)
    {
        if(y==0 || y==24)
        {
            for(int j=0;j<25; j++) 
            printf("# ");
        }
        else
        {
            for(int x=0; x<50; x++)
            {
                if(x==0 || x== 49)
                printf("#");
                else if(x==xHead && y== yHead)
                printf("O");
                else if(x==xFruit && y== yFruit)
                printf("*");
                else
                {
                    int flag1 =0;
                    for(int temp =0; temp<snakeLen; temp++)
                    {
                        if(x==xSnake[temp] && y== ySnake[temp])
                        {
                            printf("o");
                            flag1=1;
                            break;
                        }
                    }
                    if(flag1==0)
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

void setup()
{
    spawnFruit();
    xSnake[0]= 4;
    ySnake[0]= 5;
    xSnake[1]= 3;
    ySnake[1]= 5;
}

//Movement mechanics:
//prevPt stores the position of last point
//Next Point is moved to the point before it
//Head is adjusted according to the input direction
int move()
{
    if(kbhit())
    {
        switch(getch())
       {
         case 'w':
             CoordFlag = 1;
             break;
            case 'a':
             CoordFlag = 2;
             break;
          case 's':
              CoordFlag = 3;
             break;
         case 'd': 
             CoordFlag = 4;
                break;
         case 'q':
              CoordFlag = 5;
         }
    }
   return CoordFlag;
}

void logic()
{
    int xPrevPt= xHead;
    int yPrevPt= yHead;
    switch(CoordFlag)
    {
        case 1: 
            yHead--;
            break;
        case 2:
            xHead--;
            break;
        case 3: 
            yHead++;
            break;
        case 4: 
            xHead++;
            break;
        case 5:
            gameOver=1;
            break;
    }
    for(int i= 0; i<snakeLen; i++)
    {
        int xtemp = xPrevPt;
        int ytemp = yPrevPt;
        xPrevPt = xSnake[i];
        yPrevPt = ySnake[i];
        xSnake[i]= xtemp;
        ySnake[i]= ytemp;
    }
    if(xHead==xFruit&& yHead== yFruit)
    {
        snakeLen++;
        xSnake[snakeLen-1]= xPrevPt;
        ySnake[snakeLen-1]= yPrevPt;
        xFruit=0;
        yFruit=0;
        spawnFruit();
    }
    else if(xHead==0 || xHead==50 || yHead==0 || yHead==25)
    {
        gameOver=1;
    }
}

int main()
{
    printf("\nChoose Level");
    int level;
    printf("\n1: Easy");
    printf("\n2: Medium");
    printf("\n3: Hard\n");
    scanf("%d", &level);
    setup();
    while(gameOver==0)
    {
        draw();
        move();
        logic();
        Sleep(1000/level);
    }
    printf("\n\nGAME OVER! You got %d points", snakeLen*level);
}