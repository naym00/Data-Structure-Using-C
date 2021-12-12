
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
typedef struct _carrier
{
    binaryTree *head;
} carrier;
carrier *create_object()
{
    carrier *node = (carrier *)malloc(sizeof(carrier));
    node->head = NULL;
    return node;
}
void insertDataToNode(carrier *object, int data)
{
    binaryTree *newNode=(binaryTree*)malloc(sizeof(binaryTree));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    if(object->head==NULL)
    {
        object->head=newNode;
    }
    else
    {
        binaryTree *temporary=object->head;
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
    carrier *object[2] = {create_object(), create_object()};
    insertDataToNode(object[0], 10);
    insertDataToNode(object[0], 20);
    insertDataToNode(object[0], 1);
    insertDataToNode(object[0], 30);
    insertDataToNode(object[0], 11);
    insertDataToNode(object[0], 21);
    insertDataToNode(object[0], 31);
    insertDataToNode(object[0], 40);
    inOrder(object[0]->head);
    printf("\n");

    insertDataToNode(object[1], 50);
    insertDataToNode(object[1], 20);
    insertDataToNode(object[1], -1);
    insertDataToNode(object[1], 350);
    insertDataToNode(object[1], 121);
    insertDataToNode(object[1], -21);
    insertDataToNode(object[1], 31);
    insertDataToNode(object[1], 20);
    inOrder(object[1]->head);
    printf("\n");
    return 0;
}

