#include<stdio.h>
int length;
typedef struct _node
{
    int data;
    struct _node *up;
    struct _node *down;
    struct _node *left;
    struct _node *right;

    struct _node *upRight;
    struct _node *upLeft;
    struct _node *downRight;
    struct _node *downLeft;
} node;
///               ...........................
///               .upLeft     up    upRight .
///               .                         .
///               .                         .
///               .                         .
///               .left      data      right.
///               .                         .
///               .                         .
///               .                         .
///               .downLeft  down  downRight.
///               ...........................
void connectAnotherNodes(node *ptr, node *up, node *down, node *left, node *right, node *upLeft, node *upRight, node *downLeft,node *downRight)
{
    ptr->up=up;
    ptr->down=down;
    ptr->left=left;
    ptr->right=right;
    ptr->upLeft=upLeft;
    ptr->upRight=upRight;
    ptr->downLeft=downLeft;
    ptr->downRight=downRight;
}
node *createSquare(int len)
{
    length=len;
    int i, remainder;
    node *ptr = (node*)calloc(length*length, sizeof(node));
    for(i=0; i<length*length; i++)
    {
        if(i == 0)
            connectAnotherNodes(ptr+i, NULL, ptr+length, NULL, ptr+1, NULL, NULL, NULL, ptr+length+1);
        else if(i == length-1)
            connectAnotherNodes(ptr+i, NULL, ptr+i+length, ptr+i-1, NULL, NULL, NULL, ptr+i+length-1, NULL);
        else if(i == length*length-length)
            connectAnotherNodes(ptr+i, ptr+i-length, NULL, NULL, ptr+i+1, NULL, ptr+i-length+1, NULL, NULL);
        else if(i == length*length-1)
            connectAnotherNodes(ptr+i, ptr+i-length, NULL, ptr+i-1, NULL, ptr+i-length-1, NULL, NULL, NULL);
        else
        {
            if(i>=1 && i<=length-2)
                connectAnotherNodes(ptr+i, NULL, ptr+i+length, ptr+i-1, ptr+i+1, NULL, NULL, ptr+i+length-1, ptr+i+length+1);
            else if(i>=length*length-length+1 && i<=length*length-2)
                connectAnotherNodes(ptr+i, ptr+i-length, NULL, ptr+i-1, ptr+i+1, ptr+i-length-1, ptr+i-length+1, NULL, NULL);
            else
            {
                remainder = i%length;
                if(remainder == 0)
                    connectAnotherNodes(ptr+i, ptr+i-length, ptr+i+length, NULL, ptr+i+1, NULL, ptr+i-length+1, NULL, ptr+i+length+1);
                else if(remainder == length-1)
                    connectAnotherNodes(ptr+i, ptr+i-length, ptr+i+length, ptr+i-1, NULL, ptr+i-length+1, NULL, ptr+i+length-1, NULL);
                else
                    connectAnotherNodes(ptr+i, ptr+i-length, ptr+i+length, ptr+i-1, ptr+i+1, ptr+i-length-1, ptr+i-length+1, ptr+i+length-1, ptr+i+length+1);
            }
        }
    }
    return ptr;
}
void initialize(node *ptr, int startValue, int increment)
{
    int i, addValue;
    for(i=0, addValue=startValue; i<length*length; i++)
    {
        addValue +=increment;
        (ptr+i)->data=addValue;
    }
}
void printAll(node *ptr)
{
    int i, j;
    for(i=0; i<length*length; i++)
    {
        if(i%length == length-1)
            printf("%d\n", (ptr+i)->data);
        else
            printf("%d ", (ptr+i)->data);
    }
}
void printSingle(node *ptr)
{
    if(ptr!=NULL)
        printf("%d\n", ptr->data);
    else
        printf("Invalid!\n");
}
int main()
{
    node *ptr=createSquare(5);
    initialize(ptr, 10, 3);
    printAll(ptr);
    printSingle(ptr->downRight->downLeft);
    return 0;
}

