#include<stdio.h>

int binary_search(int array[], int right, int key)
{
    int left=0, mid;
    while(left<=right)
    {
        mid = (left+right) >> 1;
        if(array[mid] == key)
            return 1;
        else if(array[mid] > key)
            right = right -1;
        else if(array[mid] < key)
            left = left +1;
        if(left>right)
            return 0;
    }
}

int main()
{
    int key, array_size, array[] = {4, 7, 10, 15, 17, 22, 27, 28, 30, 34};
    array_size = sizeof(array)/sizeof(array[0]);
    scanf("%d", &key);
    if(binary_search(array, array_size-1, key) == 1)
        printf("Found\n");
    else if(binary_search(array, array_size-1, key) == 0)
        printf("Not Found\n");
    return 0;
}
