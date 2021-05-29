#include<stdio.h>
#include <stdbool.h>
int queueStartIndex = 0;
int queueLastIndex = 0;
typedef struct _matrix
{
    int column;
    struct _matrix *next;
} matrix;
typedef struct _matrixHeadLast
{
    matrix *head;
    matrix *last;
} matrixHeadLast;
matrixHeadLast *createObject()
{
    matrixHeadLast *node=(matrixHeadLast*)malloc(sizeof(matrixHeadLast));
    node->head=NULL;
    node->last=NULL;
    return node;
}
void insert(matrixHeadLast *firstNode, int column)
{
    matrix *node=(matrix*)malloc(sizeof(matrix));
    node->column=column;
    node->next=NULL;
    if(firstNode->head==NULL)
    {
        firstNode->head=node;
        firstNode->last=node;
    }
    else
    {
        firstNode->last->next=node;
        firstNode->last=node;
    }
}
int main()
{
    int i, j, numberOfNode, connectedNode, nodeValue, startNode;
    printf("Number of Node: ");
    scanf("%d", &numberOfNode);

    matrixHeadLast *node[numberOfNode];
    int *queue = (int*)calloc(numberOfNode, sizeof(int));
    int *level = (int*)calloc(numberOfNode, sizeof(int));
    bool *visited = (bool*)calloc(numberOfNode, sizeof(bool));
    matrix *matrixNode;
    for(i=0; i<numberOfNode; i++)
        node[i]=createObject();
    for(i=0; i<numberOfNode; i++)
    {
        printf("\nAdjacent node for %d\n", i+1);
        printf("How many node will be connected to node %d: ", i+1);
        for(j=scanf("%d", &connectedNode); j<=connectedNode; j++)
        {
            scanf("%d", &nodeValue);
            insert(node[i], nodeValue-1);
        }

    }
    printf("\nEnter Started Node: ");
    scanf("%d", &startNode);
    startNode = startNode - 1;
    *(queue+queueLastIndex) = startNode;
    *(visited+startNode) = true;
    queueLastIndex++;
    while(queueStartIndex < numberOfNode-1)
    {
        for(matrixNode=node[startNode]->head; matrixNode!=NULL; matrixNode=matrixNode->next)
        {
            if(*(visited+(matrixNode->column)) == false)
            {
                *(queue+queueLastIndex) = matrixNode->column;
                queueLastIndex++;
                *(visited+(matrixNode->column)) = true;
                *(level+(matrixNode->column)) = *(level+startNode) + 1;
            }
        }
        queueStartIndex++;
        startNode = *(queue+queueStartIndex);
    }
    for(i=0; i<numberOfNode; i++)
        printf("%d ", *(queue+i)+1);
    printf("\n\n");
    for(i=0; i<numberOfNode; i++)
        printf("%d %d\n", i+1, *(level+i));
    return 0;
}

/*
    2 3 4
    6
    7 8
    1 7
    8 10
    2 10
    3 4 8 9
    3 5 7
    7 10
    5 6 9
    insert(node[0], 1);
    insert(node[0], 2);
    insert(node[0], 3);

    insert(node[1], 5);

    insert(node[2], 6);
    insert(node[2], 7);

    insert(node[3], 0);
    insert(node[3], 6);

    insert(node[4], 7);
    insert(node[4], 9);

    insert(node[5], 1);
    insert(node[5], 9);

    insert(node[6], 2);
    insert(node[6], 3);
    insert(node[6], 7);
    insert(node[6], 8);

    insert(node[7], 2);
    insert(node[7], 4);
    insert(node[7], 6);

    insert(node[8], 6);
    insert(node[8], 9);

    insert(node[9], 4);
    insert(node[9], 5);
    insert(node[9], 8);
    */
