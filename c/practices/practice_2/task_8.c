#include <stdio.h>
#include <stdlib.h>

union Grade
{
    int num_mark;
    char liteal_mark;
};

int main()
{
    int n;
    printf("Hi!\nPlease enter amount of marks: ");
    scanf("%d", &n);

    union Grade grades[n];

    for (int i = 0; i < n; i++)
    {
        int mark_type;
        printf("\nPlease enter type of mark (1 - numeric mark, 2 - literal mark): ");
        scanf("%d", &mark_type);

        if (mark_type == 1)
        {
            printf("\nPlease enter mark: ");
            scanf("%d", &grades[i].num_mark);
            printf("Mark: %d\n", grades[i].num_mark);
        }
        else if (mark_type == 2)
        {
            printf("\nPlease enter mark: ");
            scanf(" %c", &grades[i].liteal_mark); // ???, я так и не понял, почему как только нету пробела все летит...
            printf("Mark: %c\n", grades[i].liteal_mark);
        }
    }
}