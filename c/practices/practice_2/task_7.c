#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    int age;
    float avg_mark;
};


int main()
{
    int n;
    printf("Hi!\nPlease enter ammount of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].avg_mark);
    }

    for (int i = 0; i < n; i++)
    {
        struct Student* stud = &students[i];
        printf("Name: %s, Age: %d, Average mark: %.1f\n", stud -> name, stud -> age, stud -> avg_mark);
    }

}