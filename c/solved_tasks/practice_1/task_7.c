// 7. Сигнал передается на Землю с частотой X ГГц (типа float).
// Если X находится в диапазоне от 2.5 до 3.5 ГГц, то связь стабильна.
// Напишите программу, проверяющую частоту сигнала.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float signal;

    printf("Hi!\nPlease enter signal frequency: ");
    scanf("%f", &signal);

    if (signal >= 2.5 && signal <= 3.5)
    {
        puts("Alright, connection is stable!");
    }
    else
    {
        puts("Sadly, but connection isn't stable!");
    }
}