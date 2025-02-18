#include <stdio.h>
#include <stdlib.h>
#include "ship.h"

void check_fuel(int fuel_level)
{
    if (fuel_level < 10) 
    {
        printf("\nCaution! Fuel level is under 10%%!\n");
    } 
    else 
    {
        printf("\nAll is OK!\n");
    }
}