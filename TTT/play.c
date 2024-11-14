#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};
int xPos[5]= {-1,-1,-1,-1,-1};
int yPos[5]= {-1,-1,-1,-1,-1};

int player_moves()
{
    printf("\nWhich box would you like to mark?\n");
    int move;
    retry:
    fflush(stdin);
    scanf("%d", &move);
    if(move>9 || move<1)
    {
        printf("Invalid box. Please enter a different choice. \t");
        goto retry;
    }
    else if(board[move-1]=='O'|| board[move-1]=='X')
    {
        printf("The box you selected is already occupied. Enter a different choice: ");
        goto retry;
    }
    else
        board[move-1]= 'X';
    return move-1;
}

int computer_moves()
{
    retry:
    srand(time(NULL));
    int move= rand()%9;
    if(board[move]!='X' && board[move]!='O')
    board[move]='O';
    else
    goto retry;
    return move;
}

int drawBoard()
{
     printf("\n");
    for (int i = 0; i < 9; i++) {
        printf(" %c ", board[i]);
        if ((i + 1) % 3 != 0) {
            printf("|");  // Column separator
        } else if (i < 8) {
            printf("\n---+---+---\n");  // Row separator after every third element
        }
    }
    printf("\n\n");
}

int checkWin()
{
    // Vertical check
    for(int i = 0; i < 3; i++)
    {
        if((board[i] == board[i + 3]) && (board[i] == board[i + 6]))  // Vertical check
        {
            if(board[i] == 'X')
                return 0;
            else if (board[i] == 'O')
                return 1;
        }
    }

    // Horizontal check
    for(int i = 0; i < 7; i += 3)
    {
        if((board[i] == board[i + 1]) && (board[i] == board[i + 2]))  // Horizontal check
        {
            if(board[i] == 'X')
                return 0;
            else if (board[i] == 'O')
                return 1;
        }
    }

    // Diagonal check from top-left to bottom-right
    if(board[0] == board[4] && board[0] == board[8])
    {
        if(board[0] == 'X')
            return 0;
        else if(board[0] == 'O')
            return 1;
    }

    // Diagonal check from top-right to bottom-left
    if(board[2] == board[4] && board[2] == board[6])
    {
        if(board[2] == 'X')  // Corrected from board[0] to board[2]
            return 0;
        else if(board[2] == 'O')
            return 1;
    }

    // No winner, continue playing
    return 2;
}

int main()
{
    drawBoard();
    for(int i=0; i<9; i++)
    {
        if(i%2==0)
            xPos[i/2] = player_moves() ;
        else
            yPos[i/2] = computer_moves();
        int res= checkWin();
            if(res==0)
            {
                printf("\nCongrats! You won! You got 5 points!\n");
                return 5;
            }
            else if(res==1)
            {
            printf("\nOh! You lost! You didn't get any points!\n");
            return 0;
        }
        drawBoard();
    }
}
