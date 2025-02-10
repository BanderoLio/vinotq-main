#include <stdio.h>

int main()
{
    // PRINT
    printf("Test out\n");
    // func puts() adds \n at the end of str

    int age;
    char name[50];

    printf("Entry ur name: ");
    fgets(name, sizeof(name), stdin);
    
    printf("Entry ur age: ");
    scanf("%d", &age); // %d = digit

    printf("Oh hell, %sU r so %d\n ", name, age); // %s = string (?)

    return 0;
}