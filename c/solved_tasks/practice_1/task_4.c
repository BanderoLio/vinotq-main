// 4. Дата старта миссии задана в виде целого числа (например, 20250210 – 10 февраля 2025 года).
// Напишите программу, которая принимает дату от пользователя и проверяет, находится ли она в будущем относительно текущей даты.

#include <stdio.h>
#include <stdlib.h> // as Vlad Ganshin said...
#include <time.h>

int main()
{
    time_t current_time = time(NULL);
    char today_date_string[20];
    char input_date_string[20];

    strftime(today_date_string, sizeof(today_date_string), "%Y%m%d", localtime(&current_time));
    printf("Hi!\nPlease enter date of mission! (Format: YYYYMMDD, for example: 20250210): ");
    fgets(input_date_string, sizeof(input_date_string), stdin);

    if (atoi(today_date_string) < atoi(input_date_string))
    {
        puts("Date of mission start is in future!");
    }
    else
    {
        puts("This mission is already started or finished!");
    }
}
