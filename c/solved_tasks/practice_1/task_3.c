// 3. Для маркировки деталей двигателя ракеты используется символ от 'A' до 'Z'.
// Напишите программу, которая принимает символ и проверяет, входит ли он в допустимый диапазон.

// Используйте char.

#include <stdio.h>

int main()
{
    char symbol;

    printf("Let's check your engine! Enter letter from this serial number: ");
    scanf("%c", &symbol);

    if ((int)symbol <= 90 && (int)symbol >= 65)
    {
        puts("It's ok!");
    }
    else
    {
        puts("Oh, this char is not in right diaposone!");
    }
}