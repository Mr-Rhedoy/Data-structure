#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int studentId;
    float dsTheoryMarks;
    float dsLabMarks;
    float averageMarks;
    char grade[3];
} Student;

typedef struct Node
{
    Student student;
    struct Node *next;
} Node;

Node *head = NULL;

void addStudent()
{
    if (head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        head->next = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = (Node *)malloc(sizeof(Node));
        temp->next->next = NULL;
        temp = temp->next;
    }
    Node *newStudent = head;
    while (newStudent->next != NULL)
    {
        newStudent = newStudent->next;
    }
    printf("Enter student name: ");
    scanf("%s", newStudent->student.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent->student.studentId);
    printf("Enter marks for DS Theory: ");
    scanf("%f", &newStudent->student.dsTheoryMarks);
    printf("Enter marks for DS Lab: ");
    scanf("%f", &newStudent->student.dsLabMarks);
    newStudent->student.averageMarks = (newStudent->student.dsTheoryMarks +
                                        newStudent->student.dsLabMarks) / 2;
    if (newStudent->student.averageMarks > 90)
    {
        strcpy(newStudent->student.grade, "A+");
    }
    else if (newStudent->student.averageMarks >= 70 && newStudent->student.averageMarks <= 90)
    {
        strcpy(newStudent->student.grade, "A");
    }
    else if (newStudent->student.averageMarks >= 50 && newStudent->student.averageMarks < 70)
    {
        strcpy(newStudent->student.grade, "B");
    }
    else
    {
        strcpy(newStudent->student.grade, "Fail");
    }
    printf("Student added successfully!\n");
}

void deleteStudent(int id)
{
    Node *temp = head;
    Node *prev = NULL;
    if (temp != NULL && temp->student.studentId == id)
    {
        head = temp->next;
        free(temp);
        printf("Student with ID %d deleted successfully!\n", id);
        return;
    }
    while (temp != NULL && temp->student.studentId != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Student with ID %d not found!\n", id);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student with ID %d deleted successfully!\n", id);
}

void viewStudentList()
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("Student list is empty!\n");
        return;
    }
    printf("Student List:\n");
    printf("Name\tID\tDS Theory\tDS Lab\tAverage\tGrade\n");
    while (temp != NULL)
    {
        printf("%s\t%d\t%.2f\t\t%.2f\t%.2f\t%s\n", temp->student.name, temp->student.studentId,
               temp->student.dsTheoryMarks, temp->student.dsLabMarks, temp->student.averageMarks,
               temp->student.grade);
        temp = temp->next;
    }
}

Node *searchStudentById(int id)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->student.studentId == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    int choice, id;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. View Student List\n");
        printf("4. Search Student by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            printf("Enter student ID to delete: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;
        case 3:
            viewStudentList();
            break;
        case 4:
            printf("Enter student ID to search: ");
            scanf("%d", &id);
            Node *found = searchStudentById(id);
            if (found != NULL)
            {
                printf("Student found!\n");
                printf("Name\tID\tDS Theory\tDS Lab\tAverage\tGrade\n");
                printf("%s\t%d\t%.2f\t\t%.2f\t%.2f\t%s\n", found->student.name, found->student.studentId,
                       found->student.dsTheoryMarks, found->student.dsLabMarks, found->student.averageMarks,
                       found->student.grade);
            }
            else
            {
                printf("Student not found!\n");
            }
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);
    return 0;
}
