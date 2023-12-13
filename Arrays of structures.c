#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int rollno;
    int age;
    float cgpa;
};

int main() {
    int n; // Declare n here, not in the struct definition
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare an array of struct student with the size n
    struct student s[n];

    for (int i = 0; i < n; i++) { // Use < instead of <=
        printf("Enter the name: ");
        scanf("%s", s[i].name); // No & needed for strings
        printf("Enter the Roll No.: ");
        scanf("%d", &s[i].rollno);
        printf("Enter the Age: ");
        scanf("%d", &s[i].age);
        printf("Enter the CGPA: ");
        scanf("%f", &s[i].cgpa);
    }

    for (int i = 0; i < n; i++) { // Use < instead of <=
        printf("\n\nName: %s", s[i].name);
        printf("\nRoll No.: %d", s[i].rollno);
        printf("\nAge: %d", s[i].age);
        printf("\nCGPA: %.2f", s[i].cgpa); // Format CGPA with two decimal places
    }

    return 0;
}
