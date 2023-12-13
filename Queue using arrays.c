#include <stdio.h>
#define MAX 5
int queue[MAX];
int rear=-1,front=-1,size=0;
void enqueue(int data)
{
    if(size<=MAX)
    {
        if(size==0)
        {
            front=0;
            rear=0;
        }
        else if(rear>=MAX-1 && size<MAX)
        {
            rear=0;
        }
        else{
            rear+=1;
        }
        queue[rear]=data;
        size+=1;
    }
    
}
void dequeue(){
    if(size<=0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        size--;
        front++;
    }
}
void display(){
    for(int i=front,s=size;s>0;s--,i++)
    {
        if(i>=MAX)
        {
            i=0;
        }
        printf("%d\t",queue[i]);
    }
}
int main() {
    int ch;
    int value;
   
    printf("\n\t queue OPERATIONS USING ARRAY");
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
    do
    {
        printf("\nEnter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            
                printf("Enter data: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            
            case 2:
            
                dequeue();
                display();
                break;
            
            case 3:
            
                display();
                break;
           
            case 4:
            
                printf("\n\t EXIT POINT ");
                break;
            
            default:
            
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            
                
        }
    }
    while(ch!=4);
    return 0;
}
