// 12. Для стабилизации корабля гироскопы работают с углом от -180° до 180°.
// Напишите программу, которая принимает угол (целое число int) и проверяет, выходит ли он за допустимый диапазон.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree;

    printf("Hi!\nPlease enter current degree of our sheep: ");
    scanf("%d", &degree);

    if (degree < -180 || degree > 180)
    {
        puts("Sorry, i can work only with degree in diaposone from -180 to 180!");
    }
    else
    {
        puts("Ok, got it!");
    }
}