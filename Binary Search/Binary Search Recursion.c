#include<stdio.h>

int bst(int array[], int left, int right, int key)
{
    int mid = (left + right) >> 1;
    if (left>right)
        return 0;

    if(array[mid] == key)
        return 1;
    else if(array[mid] > key)
        bst(array, left, mid-1, key);
    else if(array[mid] < key)
        bst(array, mid+1, right, key);
}
int main()
{
    int key, array_size, array[] = {5,10, 15, 20, 22, 25, 30, 35, 40, 50};
    array_size = sizeof(array)/sizeof(array[0]);
    scanf("%d", &key);
    if(bst(array, 0, array_size-1, key)==1)
        printf("Found\n");
    else if(bst(array, 0, array_size-1, key)==0)
        printf("Not Found\n");
    return 0;
}
