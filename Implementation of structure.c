#include <stdio.h>
#include <stdlib.h>
struct student{
    char name[100];
    int rollno;
    int age;
    float cgpa;
}akshay;
int main(){
    printf("Enter name: ");
    scanf("%s",&akshay.name);
    printf("Enter Rollno: ");
    scanf("%d",&akshay.rollno);
    printf("Enter Age: ");
    scanf("%d",&akshay.age);
    printf("Enter CGPA: ");
    scanf("%f",&akshay.cgpa);
    
    printf("\nName : %s",akshay.name);
    printf("\nRollno : %d",akshay.rollno); 
    printf("\nAge : %d",akshay.age);
    printf("\nCGPA : %f",akshay.cgpa);
    return 0;
}

output
Enter name: Akshay
Enter Rollno: 57
Enter Age: 19
Enter CGPA: 9.0
Name : Akshay
Rollno : 57
Age : 19
CGPA : 9.000000
