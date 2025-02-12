// 9. Передача сообщения на Землю занимает T секунд (double). 
// Напишите программу, которая принимает T и выводит время в минутах и секундах (например, 75.5 секунд → 1 минута 15.5 секунд).

#include <stdio.h>
#include <stdlib.h>

void convert(double time)
{
    int minutes = (int)(time / 60);
    double seconds = time - (minutes * 60);
    
    printf("Result of convertion: %d minute%s %.1f second%s\n", minutes, (minutes == 1 ? "" : "s"), seconds, (seconds == 1.0 ? "" : "s")); // .1f - one digit after float point
}



int main()
{
    double t;

    printf("Hi!\nPlease enter time to send message in seconds: ");
    scanf("%lf", &t);

    convert(t);
}