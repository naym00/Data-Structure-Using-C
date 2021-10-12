#include<stdio.h>
#include<string.h>
#include<stdbool.h>
/// Start -> Insert String and print String
typedef struct _string
{
    char character;
    struct _string *next;
} string;
typedef struct _stringObject
{
    string *head;
    string *last;
} stringObject;
stringObject *createObject_string()
{
    stringObject *node=(stringObject*)malloc(sizeof(stringObject));
    node->head=NULL;
    node->last=NULL;
    return node;
}
void insertString(stringObject *object, char name[])
{
    int i, size = strlen(name);
    for(i=0; i<size; i++)
    {
        string *node=(string*)malloc(sizeof(string));
        node->character=name[i];
        node->next=NULL;

        if(object->head==NULL)
        {
            object->head=node;
            object->last=node;
        }
        else
        {
            object->last->next=node;
            object->last=node;
        }
    }
}
void printString(stringObject *object)
{
    string *pri=object->head;
    if(pri!=NULL)
    {
        while(pri!=NULL)
        {
            printf("%c", pri->character);
            pri=pri->next;
        }
    }
}
/// End -> Insert String and print String

/// Start -> For path
typedef struct _intLinkList
{
    int data;
    struct _intLinkList *next;
} intLinkList;
typedef struct _intLinkListObject
{
    intLinkList *head;
    intLinkList *last;
} intLinkListObject;
intLinkListObject *createObject_int()
{
    intLinkListObject *node=(intLinkListObject*)malloc(sizeof(intLinkListObject));
    node->head=NULL;
    node->last=NULL;
    return node;
}
void insertData(intLinkListObject *object, int data)
{
    intLinkList *node=(intLinkList*)malloc(sizeof(intLinkList));
    node->data=data;
    node->next=NULL;

    if(object->head==NULL)
    {
        object->head=node;
        object->last=node;
    }
    else
    {
        object->last->next=node;
        object->last=node;
    }
}
void copy(intLinkListObject *to, intLinkListObject *from)
{
    intLinkList *x=from->head;
    if(x!=NULL)
    {
        while(x!=NULL)
        {
            insertData(to, x->data);
            x = x->next;
        }
    }
}
int nthValue(intLinkListObject *object, int i)
{
    intLinkList *x=object->head;
    int j = 0;
    if(x!=NULL)
    {
        while(x!=NULL)
        {
            if (i == j)
            {
                return x->data;
            }
            j++;
            x = x->next;
        }
    }
    return -1;
}
/// End -> For path
typedef struct _statusCarrier
{
    bool state;
    intLinkListObject *path;
    double cost;
} statusCarrier;

typedef struct _graphInformation
{
    bool isItOne;
    double value;
} graphInformation;
int main()
{
    int i, j, k, l, m, nth, lowest, startingNode=0, goalNode=14;
    statusCarrier status[15];
    for(i=0; i<15; i++)
        status[i].path = createObject_int();

    stringObject *originalName[15];
    for(i=0; i<15; i++)
        originalName[i] = createObject_string();

    insertString(originalName[0], "Sadarghat");
    insertString(originalName[1], "Gulistan");
    insertString(originalName[2], "Zero Point");
    insertString(originalName[3], "Motijheel");
    insertString(originalName[4], "DU TSC");
    insertString(originalName[5], "Paltan");
    insertString(originalName[6], "Shahbagh");
    insertString(originalName[7], "Supreme Court");
    insertString(originalName[8], "Hatirjheel");
    insertString(originalName[9], "Shakura");
    insertString(originalName[10], "Kakrail");
    insertString(originalName[11], "Kawran Bazar");
    insertString(originalName[12], "Basundhara Mall");
    insertString(originalName[13], "Anand Hall");
    insertString(originalName[14], "UAP");

    for(i=0; i<15; i++)
    {
        status[i].state = 0;
        status[i].cost = 2000;
    }
    graphInformation matrix[15][15] = {
        {{0, 0}, {1, 2.2}, {0, 0}, {1, 5.3}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 0.4}, {0, 0}, {1, 2.4}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1.8}, {1, 0.27}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 2.5}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 5.4}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1.1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0.7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0.4}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 2.4}, {0, 0}, {0, 0}, {0, 0}, {1, 0.45}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 4.9}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1.4}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 1.8}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0.5}, {1, 0.75}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0.75}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0.27}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}};

    double heuristic[15] = {3, 5, 6, 4, 2, 5, 8, 7, 7, 3, 6, 11, 8, 8, 0};
    int connected[15] = {2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 0};

    status[0].state = 1;
    insertData(status[0].path, startingNode);
    status[0].cost = heuristic[startingNode];
    while(true)
    {
        lowest = 3000;
        for(i=0; i<15; i++)
        {
            if(status[i].state == 1 && status[i].cost<lowest)
            {
                lowest = status[i].cost;
                m = i;
            }
        }
        for(i=1; i<= connected[status[m].path->last->data]; i++)
        {
            for(j=0; j<15; j++)
            {
                if(status[j].state == 0)
                {
                    status[j].path->head = NULL;

                    copy(status[j].path, status[m].path);
                    for(l=0, nth=1; l<15; l++)
                    {
                        if(matrix[status[m].path->last->data][l].isItOne == 1)
                        {
                            if(nth == i)
                            {
                                insertData(status[j].path, l);
                                break;
                            }
                            else
                                nth++;
                        }
                    }
                    status[j].cost = 0;
                    for(k=1; nthValue(status[j].path, k)!=-1; k++)
                        status[j].cost += matrix[nthValue(status[j].path, k-1)][nthValue(status[j].path, k)].value;
                    status[j].cost += heuristic[status[j].path->last->data];
                    status[j].state = 1;
                    if(status[j].path->last->data == goalNode)
                    {
                        status[m].state = 0;
                        for(k=0; nthValue(status[j].path, k)!=-1; k++)
                        {
                            if(nthValue(status[j].path, k) == goalNode)
                                printString(originalName[nthValue(status[j].path, k)]);
                            else
                            {
                                printString(originalName[nthValue(status[j].path, k)]);
                                printf(" -> ");
                            }
                        }
                        printf("\nCost: %0.2lf\n", status[j].cost);
                        return 0;
                    }
                    break;
                }
            }
        }
        status[m].state = 0;
    }
    return 0;
}
