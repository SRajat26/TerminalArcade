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
}