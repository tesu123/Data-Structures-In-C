#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    bool isSwapped = false;
    for (i = 0; i < n; i++)
    {
        isSwapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                isSwapped = true;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!isSwapped)
        {
            // no swapping is done. Hence, break the loop
            break;
        }
    }
}
*/

// Function to print an array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 45, 11, 23, 67, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nThe array before sorting: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("\nThe array after sorting: ");
    printArray(arr, n);

    return 0;
}