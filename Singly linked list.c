#include <stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_position();
void delete_begin();
void delete_end();
void delete_position();
void search();
void count();

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

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
                display();
                break;
            case 4:
                insert_end();
                display();
                break;
            case 5:
                insert_position();
                display();
                break;
            case 6:
                delete_begin();
                display();
                break;
            case 7:
                delete_end();
                display();
                break;
            case 8:
                delete_position();
                display();
                break;
            case 9:
                count();
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
    if (head == NULL) {
        head = temp;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nList is empty! \n");
        return;
    } else {
        ptr = head;
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
    temp->next = head;
    head = temp;
}

void insert_end() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->info);
    ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insert_position() {
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position for the new node to be inserted: ");
    scanf("%d", &pos);
    printf("\nEnter the data value of the node: ");
    scanf("%d", &temp->info);
    for (i = 0, ptr = head; i < pos - 1; i++) {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_begin() {
    struct node *ptr;
    ptr = head;
    head = head->next;
    printf("\nThe deleted element is: %d \n", ptr->info);
    free(ptr);
}

void delete_end() {
    struct node *temp, *ptr;
    ptr = head;
    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    printf("\nThe deleted element is: %d \n", ptr->info);
    free(ptr);
}

void delete_position() {
    int i, pos;
    struct node *temp, *ptr;
    printf("\nEnter the position of the node to be deleted: ");
    scanf("%d", &pos);
    ptr = head;
    for (i = 0; i < pos; i++) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    printf("\nThe deleted element is: %d \n", ptr->info);
    free(ptr);
}

void count() {
    int count = 0;
    struct node *ptr;
    ptr = head;
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
    ptr = head;
    while (ptr->info != val) {
        ptr = ptr->next;
        pos = pos + 1;
    }
    printf("\nThe position of the element is: %d \n", pos);
}
