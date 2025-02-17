#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int ammount;
    float price;
} Item;

int main()
{
    int n;
    printf("Hi!\nPlease enter ammount of items: ");
    scanf("%d", &n);

    Item* items = malloc(sizeof(Item) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %f", items[i].name, &items[i].ammount, &items[i].price);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Name: %s, Ammount of items: %d, Price: %.2f\n", items[i].name, items[i].ammount, items[i].price);
    }
    free(items);
}