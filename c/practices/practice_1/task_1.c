// 1. Космический челнок "Буран" принимает на борт только космонавтов с массой тела от 60 до 90 кг.
// Напишите программу, которая запрашивает у пользователя его массу и сообщает, может ли он пройти отбор.
// Используйте int для хранения массы.

#include <stdio.h>

int main()
{
    int weight = 0;
    printf("Hi!\nTry: can you get on Buran's board?\nFor it, enter your weight: ");
    scanf("%d", &weight);

    if (weight >= 60 && weight <= 90)
    {
        printf("Congrats! You can get on Buran's board!\n");
    }
    else
    {
        printf("So sad, but you can't get on Buran's board! :(\n");
    }
}