#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    int grade;
    int id;
};

struct Node
{
    struct Student std;
    struct Node *pNext;
    struct Node *pPre;
};

struct Node * pHead;
struct Node * pTail;


void FillStd(struct Student *s);
struct Node* CreateNode(struct Student s);
int AddNode(struct Student s);
void PrintStd(struct Node *n);
void Pop();
int PrintMenu();


int main()
{
    int choice;
    do
    {
        system("cls");
        choice = PrintMenu();

        if(choice == 1)
        {
            struct Student std, *s;
            s = &std;
            FillStd(s);
            if(AddNode(std) == 1)
                printf("Student added.");
            else
                printf("could not add the student");
        }
        else if(choice == 2)
        {
            struct Node *n;
            if(pHead)
            {
                n = pHead;
                while(n)
                {
                    PrintStd(n);
                    n = n->pNext;
                }
            }
            getch();
        }
        else if(choice == 3)
        {
            Pop();
            getch();
        }
    }
    while(choice != 0);

    return 0;
}

int PrintMenu()
{
    int choice;
    printf("1. Add student.\n");
    printf("2. Print student.\n");
    printf("3. Pop student.\n");
    printf("0. Exit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void FillStd(struct Student *std)
{
    printf("Enter student id: ");
    scanf("%d", &std->id);
    printf("\n");
    printf("Enter student name: ");
    scanf("%s", &std->name);
    printf("\n");
    printf("Enter student grade: ");
    scanf("%d", &std->grade);
    printf("\n");
}

struct Node * CreateNode(struct Student s)
{
    struct Node * ptr;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    if(ptr)
    {
        ptr -> std = s;
        ptr -> pNext = NULL;
        ptr -> pPre = NULL;
    }

    return ptr;
}

int AddNode(struct Student s)
{
    int retVal = 0;
    struct Node * ptr;
    ptr = CreateNode(s);
    if(ptr)
    {
        retVal = 1;
        if(!pHead)
        {
            pHead = pTail = ptr;
        }
        else
        {
            pTail -> pNext = ptr;
            ptr -> pPre = pTail;
            pTail = ptr;
        }
    }

    return retVal;
}

void Pop()
{
    printf("student Id: %d\n", pTail->std.id);
    printf("student name: %s\n", pTail->std.name);
    printf("student grade: %d\n", pTail->std.grade);
    printf("\n");


    struct Node * ptr;
    ptr = pTail;
    pTail = pTail->pPre;
    pTail->pNext = NULL;
    free(ptr);
}

void PrintStd(struct Node *n)
{
    printf("student Id: %d\n", n->std.id);
    printf("student name: %s\n", n->std.name);
    printf("student grade: %d\n", n->std.grade);
    printf("\n");
}
