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
typedef struct _student
{
    stringObject *name;
    stringObject *university;
    int age;
} student;
int main()
{
    int i;
    student first;
    first.name = createString();
    first.university = createString();

    insertString(first.name, "Nayeem Hossain");
    insertString(first.university, "University of Asia Pacific");
    first.age = 25;

    printf("Name: ");
    priring(first.name, true);
    printf("\n");
    printf("University: ");
    priring(first.university, true);
    printf("\n");
    printf("Age: %d\n\n", first.age);


    student array[2];
    for(i=0; i<2; i++)
    {
        array[i].name = createString();
        array[i].university = createString();
    }
    insertString(array[0].name, "Sathy Islam");
    insertString(array[0].university, "University of Asia Pacific");
    array[0].age = 22;

    printf("Name: ");
    priring(array[0].name, true);
    printf("\n");
    printf("University: ");
    priring(array[0].university, true);
    printf("\n");
    printf("Age: %d\n\n", array[0].age);

    insertString(array[1].name, "Bithy Islam");
    insertString(array[1].university, "Borhanuddin College");
    array[1].age = 29;

    printf("Name: ");
    priring(array[1].name, true);
    printf("\n");
    printf("University: ");
    priring(array[1].university, true);
    printf("\n");
    printf("Age: %d\n", array[1].age);
    return 0;
}
