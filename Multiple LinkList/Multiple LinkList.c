#include<stdio.h>
typedef struct LinkNode
{
    int Data;
    struct LinkNode *Next;
} Node;
typedef struct RootNode
{
    Node *Head;
    Node *Last;
} Base;

Base *CreateObject()
{
    Base *Node=(Base*)malloc(sizeof(Base));
    Node->Head=NULL;
    Node->Last=NULL;
    return Node;
}
void InsertValue(int Data, Base *Object)
{
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->Data=Data;
    NewNode->Next=NULL;

    if(Object->Head==NULL)
    {
        Object->Head=NewNode;
        Object->Last=NewNode;
    }
    else
    {
        Object->Last->Next=NewNode;
        Object->Last=NewNode;
    }
}
void Print(Base *Object)
{
    Node *Print=Object->Head;
    if(Print!=NULL)
    {
        while(Print!=NULL)
        {
            printf("%d ", Print->Data);
            Print=Print->Next;
        }
        printf("\n");
    }
}

int main ()
{
    Base *Object1=CreateObject();
    InsertValue(5, Object1);
    InsertValue(10, Object1);
    InsertValue(15, Object1);
    InsertValue(20, Object1);
    InsertValue(25, Object1);
    InsertValue(30, Object1);
    Print(Object1);

    Base *Object2=CreateObject();
    InsertValue(100, Object2);
    InsertValue(105, Object2);
    InsertValue(110, Object2);
    InsertValue(115, Object2);
    InsertValue(120, Object2);
    Print(Object2);

    Base *ArrayObject[2];
    ArrayObject[0]=CreateObject();
    InsertValue(50, ArrayObject[0]);
    InsertValue(60, ArrayObject[0]);
    InsertValue(70, ArrayObject[0]);
    InsertValue(80, ArrayObject[0]);
    InsertValue(90, ArrayObject[0]);
    Print(ArrayObject[0]);

    ArrayObject[1]=CreateObject();
    InsertValue(5, ArrayObject[1]);
    InsertValue(6, ArrayObject[1]);
    InsertValue(7, ArrayObject[1]);
    InsertValue(8, ArrayObject[1]);
    InsertValue(9, ArrayObject[1]);
    Print(ArrayObject[1]);
    return 0;
}

