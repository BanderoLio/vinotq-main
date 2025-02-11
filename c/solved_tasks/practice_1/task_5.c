// 5. Орбита спутника нестабильна, если скорость отличается от расчетной на более чем 0.1 м/с. 
// Напишите программу, которая принимает расчетную (double) и фактическую (double) скорости, затем определяет, стабильна ли орбита.

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int main()
{
    double calculated_speed;
    double actual_speed;

    printf("Hi!\nPlease enter actual speed of orbit of satellite: ");
    scanf("%lf", &actual_speed);
    printf("Now please enter calculated speed of orbit of satellite: ");
    scanf("%lf", &calculated_speed);


    if (fabs(calculated_speed - actual_speed) > 0.1)
    {
        puts("Orbite is not stable!");
    }
    else
    {
        puts("Orbit is stable!");
    }
}