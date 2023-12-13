#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_position();
void delete_begin();
void delete_end();
void delete_position();
void count();
void search();

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int main(){
    int choice;
    while(1){
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
                insert_position();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_position();
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
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value for the node: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if (head==NULL){
        head=temp;
    }else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void display(){
    struct node *ptr;
    if (head==NULL){
        printf("\nlist is empty\n");
        return;
    }else{
        ptr=head;
        printf("List the elements are : \n");
        while(ptr !=NULL ){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
void insert_begin(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert at  beginning: ");
    scanf("%d",&temp->data);
    head=temp->next;
    head=temp;    
}
void insert_end(){
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert at end: ");
    scanf("%d",&temp->data);
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->next=NULL;
}
void insert_position(){
    struct node *temp,*ptr;
    int  i,pos;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the specific position to insert data: ");
    scanf("%d",&pos);
    printf("Enter value of the node: ");
    scanf("%d",&temp->data);
    ptr=head;
    for(i=1;i < pos;i++){
        ptr=ptr->next;
    }
    ptr->next=temp->next;
    ptr->next=temp;
}
void delete_begin(){
    struct node *ptr;
    ptr=head;
    head=head->next;
    printf("The deleted element is %d",ptr->data);
    free(ptr);
}
void delete_end(){
    struct node *ptr,*temp;
    ptr=head;
    while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
}
void delete_position(){
    struct node *ptr,*temp;
    int i,pos;
    ptr=head;
    printf("Enter the position to be deleted:");
    scanf("%d",&pos);
    for(i=1;i<pos;i++){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    printf("The deleted element is : %d",ptr->data);
    free(ptr);
}
void count(){
    int count=0;
    struct node *ptr;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        count++;
    }
    printf("The number of elements is:%d\n",count);
}
void search(){
    int pos=1,val;
    struct node *ptr;
    printf("Enter the value of elements to be search : ");
    scanf("%d",&val);
    ptr=head;
    while(ptr->data!=val){
        ptr=ptr->next;
	pos=pos+1;
    }
    printf("The position of the element is %d\n",pos);
}

    
