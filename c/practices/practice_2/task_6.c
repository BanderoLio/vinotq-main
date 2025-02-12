#include <stdio.h>
#include <stdlib.h>

enum Engines
{
    Gasoline,
    Diesel,
    Electric
};

struct Vehicle
{
    char mark[25];
    char model[25];
    enum Engines engine;
    int year;
};

int main()
{
    int n;
    printf("Hi!\nPlease ammount of cars: ");
    scanf("%d", &n);

    struct Vehicle vehicles[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d %d", vehicles[i].mark, vehicles[i].model, &vehicles[i].year, &vehicles[i].engine);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Mark: %s, Model: %s, Year: %d, Engine type: %s\n", vehicles[i].mark, vehicles[i].model, vehicles[i].year, vehicles[i].engine == 0 ? "Gasoline" : vehicles[i].engine == 1 ? "Disel"
                                                                                                                                                                                         : "Electric");
    }
}