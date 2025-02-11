// 10. Допустимая температура корпуса спутника находится в диапазоне от -150°C до +120°C.
// Используйте int для представления температуры и напишите программу, определяющую, лежит ли заданная температура в допустимых значениях.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char temperature[20];

    printf("Hi!\nPlease enter corpus temperature of satellite: ");
    fgets(temperature, sizeof(temperature), stdin);

    if (atoi(temperature) >= -150 && atoi(temperature) <= 120)
    {
        puts("Everything is right!");
    }
    else
    {
        puts("Alert! This temperature isn't normal!");
    }
}