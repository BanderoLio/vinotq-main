#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Event
{
    char name[30];
    struct Date date;
    char description[150];
};

int main()
{
    int n;
    printf("Hi!\nPlease enter ammount of events: ");
    scanf("%d", &n);

    struct Event events[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d %s", events[i].name, &events[i].date.day, &events[i].date.month, &events[i].date.year, events[i].description);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Name: %s, Date: %d/%d/%d, Description: %s\n", events[i].name, events[i].date.day, events[i].date.month, events[i].date.year, events[i].description);
    }
}