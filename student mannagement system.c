#include <stdio.h>
#include <string.h>

#define MAX 100  // Max number of students

// Structure to store student details
struct Student {
    char name[50];
    int id;
    float grade;
};

struct Student students[MAX]; // Array of struct
int count = 0; // Track number of students

// Function to add new student
void addStudent() {
    if(count >= MAX) {
        printf("Storage full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter student name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter student Grade: ");
    scanf("%f", &students[count].grade);

    count++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    int i;  // Declaration moved here
    for (i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name : %s\n", students[i].name);
        printf("ID   : %d\n", students[i].id);
        printf("Grade: %.2f\n\n", students[i].grade);
    }
}

// Main menu function
int main() {
    int choice;

    do {
        printf("\n===== Student Record Manager =====\n");
        printf("1. Add New Student\n");
        printf("2. View All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 3);

    return 0;
}

