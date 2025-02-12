#include <stdio.h>
#include <stdlib.h>

union Data
{
    int num;
    char str[100];
    float point_num;
};

int main()
{
    int n;
    printf("Hi!\nPlease choose your data type: ");
    scanf("%d", &n);

    union Data data;

    if (n == 1)
    {
        scanf("%d", &data.num);
        printf("Int: %d\n", data.num);
    }
    else if (n == 2)
    {
        scanf("%f", &data.point_num);
        printf("FLoat: %.1f\n", data.point_num);
    }
    else if (n == 3)
    {
        scanf("%s", data.str);
        printf("Str: %s\n", data.str);
    }
}