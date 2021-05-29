#include<stdio.h>
typedef struct _node
{
    void *data;
    size_t memorySize;
    struct _node *next;
} node;
node *head=NULL;
node *last=NULL;
void createNodeAndInsetData(void *data, size_t memorySize)
{
    int i;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=malloc(memorySize);
    for(i=0; i<memorySize; i++)
    {
        *((char *)newNode->data+i)=*((char *)data+i);
    }
    newNode->memorySize=memorySize;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        last=newNode;
    }
    else
    {
        last->next=newNode;
        last=newNode;
    }
}
node * print(node *prnt)
{
    if(prnt!=NULL)
    {
        if(prnt->memorySize==4)
        {
            printf("%d ", *(int *)prnt->data);
        }
        else if(prnt->memorySize==8)
        {
            printf("%0.2lf ", *(double *)prnt->data);
        }
        return print(prnt->next);
    }
    printf("\n");
    return;
}
int main()
{
    int intData;
    double doubleData;

    intData=10;
    createNodeAndInsetData(&intData, sizeof(int));
    intData=20;
    createNodeAndInsetData(&intData, sizeof(int));

    doubleData=10.5;
    createNodeAndInsetData(&doubleData, sizeof(double));
    doubleData=30.56;
    createNodeAndInsetData(&doubleData, sizeof(double));

    print(head);
    return 0;
}

