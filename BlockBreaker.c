#include<stdio.h>
#include<windows.h>
#include<conio.h>
int xBlock[21], yBlock[21];
int xBall=14, yBall=2, gameEnd, moveFlag=1, paddle=1, brokenblocks=0;
void setup()
{
    brokenblocks=0;
    int yValues[] = {15, 13, 11}; // Row positions
    for (int row = 0; row < 3; row++) {
        for (int i = 1; i <= 5; i++) {
            xBlock[row * 5 + i - 1] = i * 5;
            yBlock[row * 5 + i - 1] = yValues[row];
        }
    }
    xBlock[20] = 3; yBlock[20] = 17;
    xBlock[21] = 27; yBlock[21] = 17;
}
int blockCheck(int x, int y)
{
    for(int k=0; k<25; k++)
    {
        if(xBlock[k]==x && yBlock[k]==y)
        {
            return 1;
        }
    }
    return 0;
}
void drawGame()
{
    for(int y=20; y>=0;y--)
    {
        for(int x=0; x<=30; x++)
        {
            if(y==20 || y==0)
            {
                for(int a=0; a<=15; a++)
                    printf("* ");
                break;
            }
            else if(x==0 || x==30){
                printf("*");
            }
            else if(x==xBall && y==yBall)
                printf("O");
            else if(blockCheck(x,y))
                printf("#");
            else if(y==1 && x== paddle)
            {
                printf("---------");
                x=x+8;
            }
            else 
                printf(" ");
        }
        printf("\n");
    }
}
void checkWallHit()
{
    if(xBall==29)
    {
        if(moveFlag==1)
            moveFlag=2;
        else
            moveFlag=4;
    }
    else if(xBall==1)
    {
        if(moveFlag==2)
            moveFlag=1;
        else
            moveFlag=3;
    }
    else if(yBall==19)
    {
        if(moveFlag==1)
            moveFlag=3;
        else
            moveFlag=4;
    }
    else if(yBall==0)
    {
        gameEnd=1;
        printf("Game over");
    }
    if(yBall==1 && xBall>=paddle && xBall<=paddle+9)
    {
        if(moveFlag==3)
            moveFlag=1;
        else
            moveFlag=2;
    }
}
void updateBallPosition()
{
    switch(moveFlag)
    {
        case 1:
            xBall++;
            yBall++;
            break;
        case 2: 
            xBall--;
            yBall++;
            break;
        case 3:
            xBall++;
            yBall--;
            break;
        case 4:
            xBall--;
            yBall--;
            break;
    }
}
void PaddleControl()
{
    if(kbhit())
    {
        char ch = getch();
        fflush(stdin);
        switch(ch)
        {
            case 'd':
                if (paddle + 9 < 30) // Check right boundary
                    paddle++;
                break;
            case 'a':
                if (paddle > 1) // Check left boundary
                    paddle--;
                break;
        }
    while (kbhit()) getch();
    }
}
void checkBlockHit()
{
    for (int k = 0; k < 25; k++)
    {
        if (xBlock[k] == -1 && yBlock[k] == -1)
            continue;
        if ((moveFlag == 1 && xBlock[k] == xBall + 1 && yBlock[k] == yBall + 1) || // Moving down-right, hitting top-left
            (moveFlag == 2 && xBlock[k] == xBall - 1 && yBlock[k] == yBall + 1) || // Moving down-left, hitting top-right
            (moveFlag == 3 && xBlock[k] == xBall + 1 && yBlock[k] == yBall - 1) || // Moving up-right, hitting bottom-left
            (moveFlag == 4 && xBlock[k] == xBall - 1 && yBlock[k] == yBall - 1))   // Moving up-left, hitting bottom-right
        {
            brokenblocks++;
            if (moveFlag == 1) moveFlag = 4; // Down-right -> Up-left
            else if (moveFlag == 2) moveFlag = 3; // Down-left -> Up-right
            else if (moveFlag == 3) moveFlag = 2; // Up-right -> Down-left
            else if (moveFlag == 4) moveFlag = 1; // Up-left -> Down-right
            xBlock[k] = -1;
            yBlock[k] = -1;
            break;
        }
        if (yBlock[k] == yBall && (xBlock[k] == xBall + 1 || xBlock[k] == xBall - 1))
        {
            if(moveFlag==1)
                moveFlag==2;
            else if(moveFlag==3)
                moveFlag=4;
            else
                moveFlag=moveFlag-1;
            xBlock[k] = -1;
            yBlock[k] = -1;
            brokenblocks++;
            break;
        }
        if (xBlock[k] == xBall && (yBlock[k] == yBall + 1 || yBlock[k] == yBall - 1))
        {
            if (moveFlag == 1 || moveFlag == 2)
            {
                moveFlag += 2; // Change from upward to downward trajectory
            }
            else
            {
                moveFlag -= 2; // Change from downward to upward trajectory
            }
            brokenblocks++;
            xBlock[k] = -1;
            yBlock[k] = -1;
            break;
        }
    }
}
int main()
{
    setup(); // Call setup to initialize the blocks
    while(gameEnd != 1)
    {
        PaddleControl();
        updateBallPosition();
        checkWallHit();
        checkBlockHit();
        drawGame();
        Sleep(400);
        system("cls");
        if(brokenblocks==22)
        {
            printf("You beat the game! You won 250 points!\n");
            return 250;
        }
    }
    drawGame();
    printf("\nGame Over! You won %d points!", brokenblocks*5);
}
