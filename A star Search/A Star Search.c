#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct _statusCarrier
{
    bool state;
    int path[50];
    int index;
    double cost;
} statusCarrier;
typedef struct _graphInformation
{
    bool isItOne;
    double value;
} graphInformation;
int main()
{
    statusCarrier status[15];
    int i, j, k, l, m, nth, lowest, startingNode=0, goalNode=14;
    for(i=0; i<15; i++)
    {
        status[i].state = false;
        status[i].index = 0;
        status[i].cost = 2000;
    }
    char name[15][50] = {"Sadarghat", "Gulistan", "Zero Point", "Motijheel", "DU TSC", "Paltan", "Shahbagh", "Supreme Court", "Hatirjheel", "Shakura", "Kakrail", "Kawran Bazar", "Basundhara Mall", "Anand Hall", "UAP"};

    graphInformation matrix[15][15] = {
        {{false, 0}, {true, 2.2}, {false, 0}, {true, 5.3}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {true, 0.4}, {false, 0}, {true, 2.4}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1.8}, {true, 0.27}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {true, 2.5}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 5.4}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1.1}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 0.7}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 0.4}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 2.4}, {false, 0}, {false, 0}, {false, 0}, {true, 0.45}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 4.9}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1.4}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1.8}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 0.5}, {true, 0.75}, {false, 0}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 0.75}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 0.27}},
        {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}}};

    double heuristic[15] = {3, 5, 6, 4, 2, 5, 8, 7, 7, 3, 6, 11, 8, 8, 0};
    int connected[15] = {2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 0};

    status[0].state = true;
    status[0].path[0] = startingNode;
    status[0].index = 1;
    status[0].cost = heuristic[startingNode];
    for(;;)
    {
        lowest = 3000;
        for(i=0; i<15; i++)
        {
            if(status[i].state == true && status[i].cost<lowest)
            {
                lowest = status[i].cost;
                m = i;
            }
        }
        for(i=1; i<= connected[status[m].path[status[m].index-1]]; i++)
        {
            for(j=0; j<15; j++)
            {
                if(status[j].state == false)
                {
                    status[j].index = 0;
                    for(k=0; k<status[m].index; k++)
                    {
                        status[j].path[k] = status[m].path[k];
                        status[j].index++;
                    }
                    for(l=0, nth=1; l<15; l++)
                    {
                        if(matrix[status[m].path[status[m].index - 1]][l].isItOne == true)
                        {
                            if(nth == i)
                            {
                                status[j].path[k] = l;
                                status[j].index++;
                                break;
                            }
                            else
                                nth++;
                        }
                    }
                    status[j].cost = 0;
                    for(k=1; k<status[j].index; k++)
                        status[j].cost += matrix[status[j].path[k-1]][status[j].path[k]].value;
                    status[j].cost += heuristic[status[j].path[status[j].index -1]];
                    status[j].state = true;
                    if(status[j].path[status[j].index-1] == goalNode)
                    {
                        status[m].state = false;
                        for(k = 0; k<status[j].index; k++)
                        {
                            if(k == status[j].index-1)
                                printf("%s ", name[status[j].path[k]]);
                            else
                                printf("%s -> ", name[status[j].path[k]]);
                        }
                        printf("\nCost: %0.2lf\n", status[j].cost);
                        return 0;
                    }
                    break;
                }
            }
        }
        status[m].state = false;
    }
    return 0;
}
