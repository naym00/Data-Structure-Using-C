#include<stdio.h>
typedef struct _binaryTree
{
    int data;
    struct _binaryTree *left;
    struct _binaryTree *right;
} binaryTree;
///
///                   Value
///                    /\
///                   /  \
///                  /    \
///                 /      \
///                /        \
///               /          \
///              /            \
///             /              \
///            /                \
///           /                  \
///          /                    \
///        left                  right
///  (smaller-value)        (bigger-value)
///       Or
///  (equal-value)
///
binaryTree *head=NULL;
void insertDataToNode(int data)
{
    binaryTree *newNode=(binaryTree*)malloc(sizeof(binaryTree));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        binaryTree *temporary=head;
        while(1)
        {
            if(temporary->data>=data) /// less or equal to value
            {
                if(temporary->left==NULL)
                {
                    temporary->left=newNode;
                    break;
                }
                else
                {
                    temporary=temporary->left;
                }
            }
            else /// bigger value
            {
                if(temporary->right==NULL)
                {
                    temporary->right=newNode;
                    break;
                }
                else
                {
                    temporary=temporary->right;
                }
            }
        }
    }
}

void inOrder(binaryTree *ptr)
{
    if(ptr==NULL)
        return;
    inOrder(ptr->left);
    printf("%d ", ptr->data);
    inOrder(ptr->right);
}
void preOrder(binaryTree *ptr)
{
    if(ptr==NULL)
        return;
    printf("%d ", ptr->data);
    inOrder(ptr->left);
    inOrder(ptr->right);
}
void postOrder(binaryTree *ptr)
{
    if(ptr==NULL)
        return;
    inOrder(ptr->left);
    inOrder(ptr->right);
    printf("%d ", ptr->data);
}
int main()
{
    insertDataToNode(10);
    insertDataToNode(20);
    insertDataToNode(1);
    insertDataToNode(30);
    insertDataToNode(11);
    insertDataToNode(21);
    insertDataToNode(31);
    insertDataToNode(40);
    inOrder(head);
    return 0;
}

