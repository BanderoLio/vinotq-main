// 15. Сигналы передаются между спутниками с различными скоростями (в Кбит/с). 
// Определите, сколько минут потребуется для передачи M МБ данных.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float speed_1;
    float speed_2;
    float data;

    printf("Hi!\nPlease enter speed of first satellite (kilobits per second): ");
    scanf("%d", &speed_1);
    printf("\nPlease enter speed of second satellite (kilobits per second): ");
    scanf("%d", &speed_2);
    printf("\nPlease enter data to trasfer between satellites (megabytes): ");
    scanf("%d", &data);

    float res_1 = data * 8.0 * 1024.0 / speed_1 / 60.0;
    float res_2 = data * 8.0 * 1024.0 / speed_2 / 60.0;

    printf("\nTo transfer chosen data you need %.2f to trasfer from first to second satellite and %.2f\n to send info in the opposite side\n", res_1, res_2);
}