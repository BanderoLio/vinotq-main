// 11. Запасы кислорода измеряются в float (в процентах). 
// Если уровень ниже 15%, экипаж должен включить аварийную систему. 
// Напишите программу, проверяющую уровень кислорода.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float oxygen;
    printf("Hi!\nPlease enter current oxygen ammount (for example 0.15 (it means 15%)): ");
    scanf("%f", &oxygen);

    if (oxygen < 0.0 || oxygen > 1.0)
    {
        puts("Such a bad thing give to me incorrect data...");
    }
    else
    {
        if (oxygen < 0.15)
        {
            puts("Crew just on emergency system!");
        }
        else
        {
            puts("All is right!");
        }
    }

}