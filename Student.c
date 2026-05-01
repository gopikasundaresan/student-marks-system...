#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[30];
    int mark1, mark2, mark3;
    int total;
};

int main()
{
    struct Student s[50], temp;
    int n = 0, choice, i, j;

    while (1)
    {
        printf("\n--- Student Marks Management ---");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Rank List");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Roll No: ");
            scanf("%d", &s[n].roll);

            printf("Enter Name: ");
            scanf("%s", s[n].name);

            printf("Enter Mark1: ");
            scanf("%d", &s[n].mark1);

            printf("Enter Mark2: ");
            scanf("%d", &s[n].mark2);

            printf("Enter Mark3: ");
            scanf("%d", &s[n].mark3);

            s[n].total = s[n].mark1 + s[n].mark2 + s[n].mark3;
            n++;

            printf("Record Added!\n");
            break;

        case 2:
            printf("\nRoll\tName\tTotal");
            for (i = 0; i < n; i++)
            {
                printf("\n%d\t%s\t%d", s[i].roll, s[i].name, s[i].total);
            }
            break;

        case 3:
            for (i = 0; i < n - 1; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (s[i].total < s[j].total)
                    {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }

            printf("\n--- Rank List ---");
            for (i = 0; i < n; i++)
            {
                printf("\n%d. %s - %d", i + 1, s[i].name, s[i].total);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice!");
        }
    }

    return 0;
}
