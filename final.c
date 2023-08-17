#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int i = 0;

struct studentInfo
{
    char firstName[20];
    char lastName[20];
    int rollNumber;
    float CGPA;
    int courseId[10];
} st[500];

void addStudent()
{
    printf("Add the Student's Details\n\n");
    printf("Enter the first name of the student\n");
    scanf("%s", st[i].firstName);
    printf("Enter the last name of the student\n");
    scanf("%s", st[i].lastName);
    printf("Enter the roll number of the student\n");
    scanf("%d", &st[i].rollNumber);
    printf("Enter the CGPA of the student\n");
    scanf("%f", &st[i].CGPA);
    printf("Enter the course ID of each course of the student\n");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &st[i].courseId[j]);
    }
    i = i + 1;
}

void findByRollNumber()
{
    int temp;
    printf("Enter the roll number of the student\n");
    scanf("%d", &temp);
    for (int j = 0; j < i; j++)
    {
        if (temp == st[j].rollNumber)
        {
            printf("The student's details are\n");
            printf("The first name is %s\n", st[j].firstName);
            printf("The last name is %s\n", st[j].lastName);
            printf("The CGPA is %f\n", st[j].CGPA);
            for (int k = 0; k < 5; k++)
            {
                printf("The enrolled course Ids are %d\n", st[j].courseId[k]);
            }
        }
    }
}

void findByName()
{
    char temp[20];
    printf("Enter the First Name of the Student\n");
    scanf("%s", temp);

    for (int j = 0; j < i; j++)
    {
        if (!strcmp(st[j].firstName, temp))
        {
            printf("The student's details are\n");
            printf("The first name is %s\n", st[j].firstName);
            printf("The last name is %s\n", st[j].lastName);
            printf("The CGPA is %f\n", st[j].CGPA);
            for (int k = 0; k < 5; k++)
            {
                printf("The enrolled course Ids are %d\n", st[j].courseId[k]);
            }
        }
    }
}

void findRegisteredStudent()
{
    int temp;
    printf("Enter the course ID\n");
    scanf("%d", &temp);

    for (int j = 0; j < i; j++)
    {
        for (int d = 0; d < 5; d++)
        {
            if (temp == st[j].courseId[d])
            {
                printf("The student's details are\n");
                printf("The first name is %s\n", st[j].firstName);
                printf("The last name is %s\n", st[j].lastName);
                printf("The CGPA is %f\n", st[j].CGPA);
                for (int k = 0; k < 5; k++)
                {
                    printf("The enrolled course Ids are %d\n", st[j].courseId[k]);
                }
            }
        }
    }
}

void totalCount()
{
    printf("The total number of students currently in the system is %d\n", i);
}

void deleteStudent()
{
    int temp;
    printf("Enter the roll number of the student\n");
    scanf("%d", &temp);

    for (int j = 0; j < i; j++)
    {
        if (temp == st[j].rollNumber)
        {
            for (int k = j; k < 499; k++)
            {
                st[k] = st[k + 1];
            }
            i--;
            printf("The entered student's record deleted successfully\n");
        }
    }
}

void updateStudent()
{
    int temp;
    printf("Enter the roll number of the student\n");
    scanf("%d", &temp);

    for (int j = 0; j < i; j++)
    {
        if (temp == st[j].rollNumber)
        {
            printf("1. First Name\n"
                   "2. Last Name\n"
                   "3. Roll Number\n"
                   "4. CGPA\n"
                   "5. Courses\n");
            int choice;
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter the updated first name: ");
                    scanf("%s", st[j].firstName);
                    break;
                case 2:
                    printf("Enter the updated last name: ");
                    scanf("%s", st[j].lastName);
                    break;
                case 3:
                    printf("Enter the updated roll number: ");
                    scanf("%d", &st[j].rollNumber);
                    break;
                case 4:
                    printf("Enter the updated CGPA: ");
                    scanf("%f", &st[j].CGPA);
                    break;
                case 5:
                    printf("Enter the updated list of courses: ");
                    for (int k = 0; k < 5; k++)
                    {
                        scanf("%d", &st[j].courseId[k]);
                    }
                    break;
            }
            printf("Records updated successfully\n");
        }
    }
}

int main()
{
    int taskToPerform;
    while (1)
    {
        printf("Enter the task that you want to perform\n");
        printf("1. Add a new Student Detail\n");
        printf("2. Find the details of a Student using Roll Number\n");
        printf("3. Find the details of a Student using the First Name\n");
        printf("4. Find the details of Students using the Course Id\n");
        printf("5. Find Total number of Students\n");
        printf("6. Delete the details of a Student\n");
        printf("7. Update the details of a Student\n");
        printf("8. Exit\n");
        scanf("%d", &taskToPerform);

        switch (taskToPerform)
        {
            case 1:
                addStudent();
                break;
            case 2:
                findByRollNumber();
                break;
            case 3:
                findByName();
                break;
            case 4:
                findRegisteredStudent();
                break;
            case 5:
                totalCount();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                updateStudent();
                break;
            case 8:
                exit(0);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}
