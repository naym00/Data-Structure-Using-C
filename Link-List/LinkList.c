#include<stdio.h>
#include<stdbool.h>
typedef struct _node
{
    int data;
    struct _node *next;
} node;
void insertFirst(node **head, node **last, int data);
void deleteFirst(node **head, node **last);
void addAfterValue(node **head, node **last, int previousData, int data);
void deleteAnyValue(node **head, node **last, int data);
void insertLast(node **head, node **last, int data);
void deleteLast(node **head, node **last);
bool search(node **head, int data);
void print(node **head);
int main()
{
    node *head=NULL;
    node *last=NULL;

    insertLast(&head, &last, 20);
    insertLast(&head, &last, 30);
    insertLast(&head, &last, 50);
    print(&head);
    insertFirst(&head, &last, 10);
    print(&head);
    insertFirst(&head, &last, 60);
    print(&head);
    deleteFirst(&head, &last);
    print(&head);
    addAfterValue(&head, &last, 30, 40);
    print(&head);
    addAfterValue(&head, &last, 50, 70);
    print(&head);
    deleteAnyValue(&head, &last, 70);
    print(&head);
    deleteLast(&head, &last);
    print(&head);
    if(search(&head, 30)==true)
        printf("30 is in Link-List!\n");
    else
        printf("30 is not in Link-List!\n");
    if(search(&head, 50)==true)
        printf("50 is in Link-List!\n");
    else
        printf("50 is not in Link-List!\n");
    return 0;
}
void insertFirst(node **head, node **last, int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL)
    {
        *head=newNode;
        *last=newNode;
    }
    else
    {
        newNode->next=*head;
        *head=newNode;
    }
}
void deleteFirst(node **head, node **last)
{
    if(*head==NULL)
        printf("Link-List is empty!\n");
    else
    {
        if((*head)->next!=NULL)
            *head=(*head)->next;
        else
        {
            *head=NULL;
            *last=NULL;
        }
    }
}
void addAfterValue(node **head, node **last, int previousData, int data)
{
    if(*head==NULL)
        printf("Link-List is empty!\n");
    else
    {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data=data;
        newNode->next=NULL;
        node *ptr=*head;
        while(ptr!=NULL)
        {
            if(ptr->data==previousData)
            {
                if(ptr->next==NULL)
                {
                    ptr->next=newNode;
                    *last=newNode;
                }
                else
                {
                    newNode->next=ptr->next;
                    ptr->next=newNode;
                }
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL)
            printf("Didn't find %d!\n", previousData);
    }
}
void deleteAnyValue(node **head, node **last, int data)
{
    if(*head==NULL)
        printf("Link-List is empty!\n");
    else
    {
        if((*head)->data==data)
        {
            if((*head)->next==NULL)
            {
                *head=NULL;
                *last=NULL;
            }
            else
                *head=(*head)->next;
        }
        else
        {
            node *ptr=(*head)->next;
            node *previousPtr=*head;
            while(ptr!=NULL)
            {
                if(ptr->data==data)
                {
                    if(ptr->next==NULL)
                    {
                        previousPtr->next=NULL;
                        *last=previousPtr;
                    }
                    else
                        previousPtr->next=ptr->next;
                    break;
                }
                ptr=ptr->next;
                previousPtr=previousPtr->next;
            }
            if(ptr==NULL)
                printf("Didn't find %d!\n", data);
        }
    }
}
void insertLast(node **head, node **last, int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL)
    {
        *head=newNode;
        *last=newNode;
    }
    else
    {
        (*last)->next=newNode;
        *last=newNode;
    }
}
void deleteLast(node **head, node **last)
{
    if(*head==NULL)
        printf("Link-List is empty!\n");
    else
    {
        if(*head==*last)
        {
            *head=NULL;
            *last=NULL;
        }
        else
        {
            node *ptr=*head;
            while(ptr->next->next!=NULL)
                ptr=ptr->next;
            ptr->next=NULL;
            *last=ptr;
        }
    }
}
bool search(node **head, int data)
{
    node *ptr=*head;
    while(ptr!=NULL)
    {
        if(ptr->data==data)
            break;
        ptr=ptr->next;
    }
    if(ptr==NULL)
        return false;
    else
        return true;
}
void print(node **head)
{
    node *ptr=*head;
    if(ptr==NULL)
        printf("Link-List is empty!\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
