// 14. На Луне сила тяжести составляет 1/6 от земной.
// Напишите программу, которая принимает массу объекта (int) и вычисляет его вес на Луне (float).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const float moon_g = 1.0 / 6.0;
    int mass_on_earth;
    float mass_on_moon;

    printf("Hi!\nPlease enter weight of object on Earth in kg's: ");
    scanf("%d", &mass_on_earth);

    if (mass_on_earth <= 0)
    {
        puts("Weight of object can't be less or equal zero!");
    }
    else
    {
        mass_on_moon = moon_g * mass_on_earth;
        printf("Mass of your object on Moon is %.2f\n", mass_on_moon);
    }
}