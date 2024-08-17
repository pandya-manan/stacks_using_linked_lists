#include<stdio.h>
#include<stdlib.h>
//Basic Node structure to be used in stack using linked lists
struct Node
{
    int data;
    struct Node* next;
};
//Pop function -> to remove the top most element in the stack
struct Node* pop(struct Node* head)
{
    if(head==NULL)
    {
        printf("The stack is empty, hence cannot perform pop operation!\n");
        return head;
    }
    struct Node* ptr=head;
    head=head->next;
    printf("Element popped out successfully: %d\n",ptr->data);
    free(ptr);
    return head;
}
//Peek function ->  to view the top most element present in the stack
void peek(struct Node* head)
{
    if(head==NULL)
    {
        printf("The stack is empty!\n");
        return;
    }
    struct Node* ptr=head;
    printf("%d",ptr->data);
}
//To push an element into the stack
struct Node* push(struct Node* head, int data)
{
    struct Node* toAdd=(struct Node*)malloc(sizeof(struct Node));
    toAdd->data=data;
    toAdd->next=head;
    printf("New element added successfully: %d\n",data);
    return toAdd;
}
//Compute the length of the stack
int computeStackLength(struct Node* head)
{
    int lengthCounter=0;
    if(head==NULL)
    {
        printf("The stack is empty!\n");
        return 0;
    }
    struct Node* ptr=head;
    while(ptr!=NULL)
    {
        lengthCounter++;
        ptr=ptr->next;
    }
    return lengthCounter;
}
//Traverse a stack
void traverseStack(struct Node* head)
{
    if(head==NULL)
    {
        printf("No elements present in the stack!\n");
        return;
    }
    struct Node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
//check if stack is empty
void checkIfStackIsEmpty(struct Node* head)
{
    if(head==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    else
    {
        printf("The stack is not empty!\n");
        return;
    }
}
int main()
{
    struct Node* head=NULL;
    int choice,data,result=0;
    while(1)
    {
        printf("Menu operations for a stack\n");
        printf("1.Push an element\n");
        printf("2.Pop an element\n");
        printf("3.Check if stack is full or empty\n");
        printf("4.Length of the stack\n");
        printf("5.Display the stack elements\n");
        printf("6.Exit\n");
        printf("Enter your choice from the above given options\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element which needs to be added\n");
                    scanf("%d",&data);
                    head=push(head,data);
                    break;
            case 2: head=pop(head);
                    break;
            case 3: checkIfStackIsEmpty(head);
                    break;
            case 4: result=computeStackLength(head);
                    printf("Current length of the stack is: %d\n",result);
                    break;
            case 5: traverseStack(head);
                    break;
            case 6: printf("Sad to see you go! GoodBye!\n");
                    exit(1);
                    break;
            default:printf("Please enter the correct option from the given options available! Thank you!\n");
            

        }   
    }
}