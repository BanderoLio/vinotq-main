#include <stdio.h>
#include <stdlib.h>

struct Cource
{
    char name[100]; // зная наши курсы и их назавния...
    int cresidts;   // ??? что это
    char teacher[50];
};

int main()
{
    int n;
    printf("Hi!\nPlease enter amount of cources: ");
    scanf("%d", &n);

    struct Cource cources[n];

    for (int i = 0; i < n; i++)
    {
        printf("Please enter name of cource, credits on cource and teacher of the cource: ");
        scanf("%s %d %s", cources[i].name, &cources[i].cresidts, cources[i].teacher);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Cource: %s, Credits: %d, Teacher: %s\n", cources[i].name, cources[i].cresidts, cources[i].teacher);
    }
}