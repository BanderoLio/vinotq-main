// Структуры данных в C. Перечисления (Enumerations)

#include <stdio.h>
#include <stdlib.h>

enum Day
{
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

int main()
{
    enum Day today = Sunday;
    printf("Today is: %d\n", today); // 0 for Sunday
}
