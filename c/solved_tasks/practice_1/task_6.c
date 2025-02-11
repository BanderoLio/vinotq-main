// 6. В космической экспедиции участвуют заранее подготовленные космонавты.
// Для предстоящего полета подготовлены модульные отсеки для космического корабля.
// Космическая программа профинансировала изготовление 3-х вариантов модулей, которые вмещают 2-х человек экипажа, 3-х или 4-х человек.
// По итогу отбора участников, будет выяволено общее число претендентов на экспедицию.
// Напишите программу, которая определит можно ли разделить число отобранных участников на равные группы, где каждая группа может содержать 2, 3 или 4 человека.
// На вход программа принимает количество космонавтов и выводит, можно ли их разделить без остатка, а также сколько потребуется полностью заполненных модулей и какого типа: 2-х, 3-х или 4-х местные.
// Программа должна рассчитать всевозможные варианты комплектаций модулями, исключая непоместившегося космонавта (если такой будет).

#include <stdio.h>
#include <stdlib.h>

void split(int astronauts)
{
    for (int four_module = astronauts / 4; four_module >= 0; four_module--)
    {
        for (int three_module = (astronauts - 4 * four_module) / 3; three_module >= 0; three_module--)
        {
            int two_module = (astronauts - 4 * four_module - 3 * three_module) / 2;
            
            if (4 * four_module + 3 * three_module + 2 * two_module == astronauts)
            {
                printf("We have 4-place modules: %d, 3-place modules: %d, 2-place modules: %d\n", four_module, three_module, two_module);
            }
        }
    }
    puts("This is all combinations");
}

int main()
{
    int astronauts;
    printf("Hi!\nPlease enter ammount of astronauts: ");
    scanf("%d", &astronauts);
    split(astronauts);
}