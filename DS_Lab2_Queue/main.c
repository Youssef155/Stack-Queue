#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    int grade;
    int id;
};

struct Student std[5];
int top=0, rear=0;


void FillStd(int i);
void Enqueue();
void PrintStd(struct Student std);


int main()
{

    int choice;

    do
    {
        system("cls");
        choice = PrintMenu();

        if(choice == 1)
        {
            Enqueue();
            getch();
        }
        else if(choice == 2)
        {
            for(int i=0; i<rear; i++)
            {
                PrintStd(std[i]);
            }
            getch();
        }
        else if (choice == 3)
        {
            Dequeue();
            getch();
        }

    }while(choice != 0);

    return 0;
}

int PrintMenu()
{
    int choice;
    printf("1. Enqueue student.\n");
    printf("2. Display students.\n");
    printf("3. Dequeue student.\n");
    printf("0. Exit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void FillStd(int i)
{
    printf("Enter student id: ");
    scanf("%d", &std[i].id);
    printf("\n");
    printf("Enter student name: ");
    scanf("%s", std[i].name);
    printf("\n");
    printf("Enter student grade: ");
    scanf("%d", &std[i].grade);
    printf("\n");
}

void Enqueue()
{
    if(rear < 5)
    {
        FillStd(rear);
        printf("Student add.\n");
        rear++;
    }
}

void Dequeue()
{
    if(rear != 0)
    {
        PrintStd(std[0]);
        rear--;
    }
    else
    {
        printf("Queue is empty.");
    }
}

void PrintStd(struct Student s)
{
    printf("student Id: %d\n", s.id);
    printf("student name: %s\n", s.name);
    printf("student grade: %d\n", s.grade);
    printf("\n");
}
