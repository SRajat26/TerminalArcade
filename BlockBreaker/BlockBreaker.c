#include<stdio.h>

// int xBlock[25], yBlock[25], paddle[8]={2,3,4,5,6,7,8};
// int xBall=4, yBall=50;
// void setup()
// {
//  //put values in xBlock and yBock to store initial positions of blocks
// }
void main()
{
    for(int y=20; y>=0;y--)
    {
        for(int x=0; x<=75; x++)
        {
            if(y==20 || y==0)
            {for(int a=0; a<=37; a++)
            printf("* ");
            break;
            }
            else if(x==0 || x==75){
            printf("*");
            }
            else
            printf(" ");
            // for(int k=0; k<25; k++)
            // {
            //     if(xBlock[k]==x && yBlock[k]==y)
            //     {
            //         printf("# ");
            //         x++;
            //         break;
            //     }

            // }
        }
        printf("\n");
    }
}