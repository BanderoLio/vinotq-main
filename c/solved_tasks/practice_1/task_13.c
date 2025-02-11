// 13. Международная станция "Сириус" принимает N космонавтов.
// Они прибывают группами по 2 человека.
// Напишите программу, проверяющую, можно ли всех доставить без остатка.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Hi!\nPlease enter ammount of astronauts: ");
    scanf("%d", &n);

    if (n < 0)
    {
        puts("We can't send negative ammount of astronauts!");
    }
    else
    {
        if (n % 2 == 0)
        {
            puts("Alright! All astronauts can reach Sirius!");
        }
        else
        {
            puts("Saddly, but 1 astronaut can't reach Sirius! He hasn't got pair!");
        }
    }
}