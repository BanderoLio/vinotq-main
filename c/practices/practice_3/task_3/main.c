#include <stdio.h>
#include <stdlib.h>
#include "ship.h"

int main ()
{
    float speed, time;
    int fuel_level;

    printf("Hi!\nPlease enter your ship's speed (in km/h, may be float): ");
    scanf("%f", &speed);
    printf("Now please enter your ship's travel time (in hours, may be float): ");
    scanf("%f", &time);

    float distance = calculate_distance(speed, time);
    printf("\nAccording to my calculations, your travel will be: %.2f km!\n", distance);

    printf("\nOh, forget it. Please enter your current fuel level (in %%): ");
    scanf("%d", &fuel_level);

    check_fuel(fuel_level);
}

