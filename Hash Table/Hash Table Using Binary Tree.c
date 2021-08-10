#include<stdio.h>
#include<stdbool.h>
int tableSize;
typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
} node;
typedef struct _nodeTypeAddress
{
    node *head;
} nodeTypeAddress;
nodeTypeAddress *createNode()
{
    nodeTypeAddress *newNode=(nodeTypeAddress*)malloc(sizeof(nodeTypeAddress));
    newNode->head=NULL;
    return newNode;
}
void insertDataToNode(nodeTypeAddress *object, int data)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    if(object->head==NULL)
        object->head=newNode;
    else
    {
        node *temporary=object->head;
        while(true)
        {
            if(temporary->data>=data)
            {
                if(temporary->left==NULL)
                {
                    temporary->left=newNode;
                    break;
                }
                else
                    temporary=temporary->left;
            }
            else
            {
                if(temporary->right==NULL)
                {
                    temporary->right=newNode;
                    break;
                }
                else
                    temporary=temporary->right;
            }
        }
    }
}
void preOrder(node *ptr)
{
    if(ptr == NULL)
        return;
    printf("%d ", ptr->data);
    preOrder(ptr->left);
    preOrder(ptr->right);
}
void inOrder(node *ptr)
{
    if(ptr == NULL)
        return;
    inOrder(ptr->left);
    printf("%d ", ptr->data);
    inOrder(ptr->right);
}
void postOrder(node *ptr)
{
    if(ptr == NULL)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d ", ptr->data);
}
bool checkOne(node *ptr, int data)
{
    while(true)
    {
        if(ptr->data>data)
        {
            if(ptr->left!=NULL)
            {
                ptr=ptr->left;
            }
            else
                break;
        }
        else if(ptr->data<data)
        {
            if(ptr->right!=NULL)
            {
                ptr=ptr->right;
            }
            else
                break;
        }
        else
            break;
    }
    if(ptr->data==data)
        return true;
    else
        return false;
}
int hashFunction(int value)
{
    return value%tableSize;
}

int main()
{
    int i;
    printf("Enter the size of Hash Table: ");
    scanf("%d", &tableSize);
    nodeTypeAddress *root[tableSize];
    for(i=0; i<tableSize; i++)
        root[i]=createNode();

    insertDataToNode(root[hashFunction(40)], 40);
    insertDataToNode(root[hashFunction(10)], 10);
    insertDataToNode(root[hashFunction(20)], 20);
    insertDataToNode(root[hashFunction(1)], 1);
    insertDataToNode(root[hashFunction(30)], 30);
    insertDataToNode(root[hashFunction(11)], 11);
    insertDataToNode(root[hashFunction(21)], 21);
    insertDataToNode(root[hashFunction(31)], 31);
    insertDataToNode(root[hashFunction(10)], 10);
    insertDataToNode(root[hashFunction(201)], 201);
    insertDataToNode(root[hashFunction(15)], 15);
    insertDataToNode(root[hashFunction(301)], 301);
    insertDataToNode(root[hashFunction(113)], 113);
    insertDataToNode(root[hashFunction(217)], 217);
    insertDataToNode(root[hashFunction(318)], 318);
    insertDataToNode(root[hashFunction(404)], 404);
    insertDataToNode(root[hashFunction(106)], 106);
    insertDataToNode(root[hashFunction(2032)], 2032);
    insertDataToNode(root[hashFunction(14)], 14);
    insertDataToNode(root[hashFunction(802)], 802);
    insertDataToNode(root[hashFunction(118)], 118);
    insertDataToNode(root[hashFunction(219)], 219);
    insertDataToNode(root[hashFunction(316)], 316);
    insertDataToNode(root[hashFunction(403)], 403);
    insertDataToNode(root[hashFunction(104)], 104);
    insertDataToNode(root[hashFunction(205)], 205);
    insertDataToNode(root[hashFunction(18)], 18);
    insertDataToNode(root[hashFunction(306)], 306);
    insertDataToNode(root[hashFunction(17)], 17);
    insertDataToNode(root[hashFunction(21)], 21);
    insertDataToNode(root[hashFunction(13)], 13);
    insertDataToNode(root[hashFunction(14)], 14);
    insertDataToNode(root[hashFunction(405)], 405);

    for(i=0; i<tableSize; i++)
    {
        inOrder(root[i]->head);
        printf("\n");
    }
    if(checkOne(root[2]->head, 1)==true)
        printf("Got it\n");
    else
        printf("Didn't get it\n");
    return 0;
}
