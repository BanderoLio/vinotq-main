// Структуры данных в C. Union

#include <stdio.h>
#include <stdlib.h>

union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;

    data.i = 10;
    printf("data.i = %d\n", data.i);

    data.f = 47.14;
    printf("data.f = %.2f\n", data.f);
    printf("data.i = %d\n", data.i);
}
