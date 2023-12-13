#include <stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void cnt();

struct node {
    int info;
    struct node *next;
};

int count;
struct node *start = NULL;

int main() {
    int choice;
    while (1) {
        printf("\n MENU ");
        printf("\n 1.Create ");
        printf("\n 2.Display ");
        printf("\n 3.Insert at the beginning ");
        printf("\n 4.Insert at the end ");
        printf("\n 5.Insert at specified position ");
        printf("\n 6.Delete from beginning ");
        printf("\n 7.Delete from the end ");
        printf("\n 8.Delete from specified position ");
        printf("\n 9.Count the number of elements ");
        printf("\n 10.Search an element ");
        printf("\n--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_pos();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_pos();
                break;
            case 9:
                cnt();
                break;
            case 10:
                search();
                break;
            default:
                printf(" Wrong Choice !");
                break;
        }
    }
    return 0;
}

void create() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nOut of Memory Space: \n");
        exit(0);
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display() {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty! \n");
        return;
    } else {
        ptr = start;
        printf("\nThe List elements are:\n");
        while (ptr != NULL) {
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

// Rest of the functions follow similarly
void insert_begin() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->info);
    temp->next = start;
    start = temp;
}

void insert_end() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->info);
    ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insert_pos() {
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position for the new node to be inserted: ");
    scanf("%d", &pos);
    printf("\nEnter the data value of the node: ");
    scanf("%d", &temp->info);
    for (i = 0, ptr = start; i < pos - 1; i++) {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_begin() {
    struct node *ptr;
    ptr = start;
    start = start->next;
    printf("\nThe deleted element is: %d \n", ptr->info);
    free(ptr);
}

void delete_end() {
    struct node *temp, *ptr;
    ptr = start;
    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    printf("\nThe deleted element is: %d \n", ptr->info);
    free(ptr);
}

void delete_pos() {
    int i, pos;
    struct node *temp, *ptr;
    printf("\nEnter the position of the node to be deleted: ");
    scanf("%d", &pos);
    ptr = start;
    for (i = 0; i < pos; i++) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    printf("\nThe deleted element is: %d \n", ptr->info);
    free(ptr);
}

void cnt() {
    int count = 0;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    printf("\nThe number of elements in the list is: %d \n", count);
}

void search() {
    int pos = 0, val;
    struct node *ptr;
    printf("\nEnter the data to be searched: ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->info != val) {
        ptr = ptr->next;
        pos = pos + 1;
    }
    printf("\nThe position of the element is: %d \n", pos);
}
