// Структуры данных в C. Struct

#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char name[50];
    int age;
    float height;
};

int main()
{
    struct Person p = {"Oleg", 47, 1.48};
    printf("Name: %s, Age: %d, Height: %.2f\n", p.name, p.age, p.height);
    printf("%d\n", sizeof(p));
    // printf("%f\n", p.height);
}
