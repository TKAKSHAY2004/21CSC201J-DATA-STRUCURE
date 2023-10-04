#include <stdio.h>
#include <stdlib.h>
struct node{
   int data;
   struct node* next;
};
struct node* head=NULL;
void push(int data)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=head;
    head=n;
}
void pop()
{
    struct node* t=head;
    head=head->next;
    printf("Popped: %d\t",t->data);
    free(t);
    printf("\n");
}
void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void search()
{
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
void count()
{
    int count=1;
    struct node *ptr;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        count++;
    }
    printf("The total numbers of elements are : %d\n",count);
}
int main()
{
    int c;
    printf("1.Push\n2.Pop\n3.Display\n4.Search\n5.count\n6.Exit\n");
    while(1){
        printf("Enter Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
            int d;
            printf("Enter data: ");
            scanf("%d",&d);
            push(d);
            break;
            }
            case 2:
            {
            pop();
            break;
            }
            case 3:
            {
            display();
            break;
            }
            case 4:
            {
            search();
            break;
            }
            case 5:
            {
            count();
            break;
            }
            case 6:
            {
                printf("Exit");
                exit(0);
            }
            default:
            {
                printf("Invalid entry");
            }
        }
    }
}
