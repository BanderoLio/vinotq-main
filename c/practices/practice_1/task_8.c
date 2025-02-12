// 8. Космический корабль может нести N кг груза (int). 
// Однако, он должен быть равномерно распределен в 4 отсеках. 
// Определите, возможно ли это, и если да, сколько кг будет в каждом отсеке.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Hi!\nPlease enter summary weight of cargo: ");
    scanf("%d", &n);

    if (n % 4 == 0)
    {
        printf("Congrats! All cargo can be splitted! It will be splitted for 4 parts %d kg each\n", n/4);
    }
    else
    {
        puts("Sorry, your cargo can't be splitted!");
    }
}