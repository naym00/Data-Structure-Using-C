#include<stdio.h>
#include<stdbool.h>
int tableSize;
typedef struct _node
{
    int data;
    struct _node *next;
} node;
typedef struct _nodeTypeAddress
{
    node *head;
    node *last;
} nodeTypeAddress;
nodeTypeAddress *createNode()
{
    nodeTypeAddress *newNode=(nodeTypeAddress*)malloc(sizeof(nodeTypeAddress));
    newNode->head=NULL;
    newNode->last=NULL;
    return newNode;
}
void insertDataToNode(nodeTypeAddress *object, int data)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    if(object->head==NULL)
    {
        object->head=newNode;
        object->last=newNode;
    }
    else
    {
        object->last->next=newNode;
        object->last=newNode;
    }
}
void print(nodeTypeAddress *object)
{
    node *ptr=object->head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}
bool checkOne(nodeTypeAddress *object, int data)
{
    node *ptr=object->head;
    while(ptr != NULL)
    {
        if(ptr->data==data)
            break;
        ptr=ptr->next;
    }
    if(ptr == NULL)
        return false;
    else
        return true;
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
    insertDataToNode(root[hashFunction(10)], 10);
    insertDataToNode(root[hashFunction(20)], 20);
    insertDataToNode(root[hashFunction(1)], 1);
    insertDataToNode(root[hashFunction(30)], 30);
    insertDataToNode(root[hashFunction(11)], 11);
    insertDataToNode(root[hashFunction(21)], 21);
    insertDataToNode(root[hashFunction(31)], 31);
    insertDataToNode(root[hashFunction(40)], 40);
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
        print(root[hashFunction(i)]);
        printf("\n");
    }
    if(checkOne(root[hashFunction(117)], 117)==true)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}


