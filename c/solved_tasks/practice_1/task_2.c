// 2. Луноход работает на солнечных батареях и может проехать не более 500 км без подзарядки. 
// Напишите программу, которая принимает расстояние до ближайшей cтанции подзарядки (целое число) 
// и проверяет, сможет ли луноход добраться до нее.

#include <stdio.h>

int main()
{
    int max_trip = 500;
    int nearest_charging_station = 0;

    printf("Hi!\nLet's calculate: can you reach nearest charging station?\nFor it, enter distance to nearest station: ");
    scanf("%d", &nearest_charging_station);

    if (max_trip < nearest_charging_station)
    {
        puts("You can't reach this station! Try another!");
    }
    else
    {
        printf("You can reach it! Calculating route to this station...\n");
    }
}