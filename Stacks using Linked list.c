#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node{
    int val;
    struct node *next;
};
struct node *head;

void main(){
    int ch=0;
    while(ch!=4){
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
        
        switch(ch){
            case 1: {
                push();
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("Exit");
            }
            default:{
                printf("please Enter valid choice");
            }
        }
    }
}

void push(){
    int val;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if (ptr==NULL){
        printf("stack overflow");
    }else{
        printf("Enter the value: ");
        scanf("%d",&val);
        if(head==NULL){
            ptr->val=val;
            ptr->next=NULL;
            head=ptr;
        }else{
            ptr->val=val;
            ptr->next=head;
            head=ptr;
        }
        printf("Item pushed");
    }
}
void pop(){
    int item;
    struct node *ptr;
    if (head == NULL){
        printf("stack underflow\n");
    }
    else{
        item=head->val;
        ptr=head;
        head = head->next;
        free(ptr);
        printf("item popped\n");
    }
}
void display(){
    int i;
    struct node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("stack is empty\n");
    }
    else{
        printf("stack elements are:\n");
        while(ptr!= NULL){
            printf("%d\n",ptr->val);
            ptr=ptr->next;
        }
    }
}
