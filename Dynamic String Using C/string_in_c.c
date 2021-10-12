#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct _string
{
    char character;
    struct _string *next;
    struct _string *previous;
} string;
typedef struct _stringObject
{
    string *head;
    string *last;
} stringObject;
stringObject *createString()
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
        node->previous=NULL;

        if(object->head==NULL)
        {
            object->head=node;
            object->last=node;
        }
        else
        {
            node->previous=object->last;
            object->last->next=node;
            object->last=node;
        }
    }
}
void priring(stringObject *object, bool flag)
{
    if(flag == true)
    {
        /// Forward
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
    else
    {
        /// Backward
        string *pri=object->last;
        if(pri!=NULL)
        {
            while(pri!=NULL)
            {
                printf("%c", pri->character);
                pri=pri->previous;
            }
        }
    }
}
int main()
{
    stringObject *object = createString();
    insertString(object, "ABC"); /// Storing String to object
    priring(object, true); /// Printing String
    printf("\n");

    priring(object, false); /// Printing Reverse String
    printf("\n");

    insertString(object, "DEF"); /// Extending String in object
    priring(object, true); /// Extended String
    printf("\n");

    priring(object, false); /// Extended Reverse String
    printf("\n");

    ///stringObject *array[2] = {createString(), createString()};
    stringObject *array[2];
    array[0] = createString();
    array[1] = createString();

    insertString(array[0], "PQR");
    insertString(array[1], "XYZ");

    priring(array[0], true);
    printf("\n");
    priring(array[0], false);
    printf("\n");

    priring(array[1], true);
    printf("\n");
    priring(array[1], false);
    printf("\n");

    return 0;
}
