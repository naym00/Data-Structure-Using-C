#include<stdio.h>
struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Last;
};
struct Node *Head=NULL;
void Insert(int Data)
{
    struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->Data=Data;
    NewNode->Next=NULL;
    NewNode->Last=NULL;
    if(Head==NULL)
    {
        NewNode->Last=NewNode;
        Head=NewNode;
    }
    else
    {
        Head->Last->Next=NewNode;
        Head->Last=NewNode;
    }
}
void Print()
{
    struct Node *X=Head;
    if(X!=NULL)
    {
        while(X!=NULL)
        {
            printf("%d ", X->Data);
            X=X->Next;
        }
        printf("\n");
    }
}
int main ()
{
    Insert(5);
    Insert(10);
    Insert(15);
    Insert(20);
    Print();

    Insert(25);
    Insert(30);
    Insert(35);
    Insert(40);
    Print();
    return 0;
}


