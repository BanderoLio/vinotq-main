#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    char name[30];
    char company_position[30];
    float salary;
};

int main()
{
    int n;
    printf("Hi!\nPlease enter ammount of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %f", employees[i].name, employees[i].company_position, &employees[i].salary);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Name: %s, Company position: %s, Salary: %.1f\n", employees[i].name, employees[i].company_position, employees[i].salary);
    }
}