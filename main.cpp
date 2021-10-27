#include <stdio.h>
#include "aggregate.h"

int main()
{
    //Testing Q3, For the error, does it have to be the line in the aggregate class or in the main class??
    float arr[] = {1, 4, 5, 6, -1};
    int size = sizeof(arr)/sizeof(float); //This is to determine the number of elements in the array
    float a = minF(arr, size);
    float b = maxF(arr, size);
    float c = sumF(arr, size);
    float d = avgF(arr, size);
    float e = pseudo_avg(arr, size);
    printf("------------Testing Q3------------\n");
    printf("Information about the array: \n Size of Array: %d\n Minimum: %f\n Maximum: %f\n Sum: %f\n Average: %f\n Pseudo-Average: %f\n", size, a, b, c, d, e);
    printf("\n");


    //Enumerating the values of the array
    float *ptr[size];
    for ( int i = 0; i < size; i++) {
        ptr[i] = &arr[i]; //assigning the address
    }
    printf("Here are the values in the default array: \n");
    for ( int i = 0; i < size; i++){
        printf(" Value of arr[%d] = %f\n", i, *ptr[i]);
    }
    printf("\n");

    //Testing the array of pointers to functions with the default array
    float (*funcPtr[5])(float arr[], int arrSize) = {minF, maxF, sumF, avgF, pseudo_avg};
    //can you return name of function for function pointer??
    printf("Functions used on the default array (arr): \n");
    for (int i = 0; i < 5; i++){
        printf(" Function %d on arr: %f\n", i+1, (*funcPtr[i])(arr, size));
    }
    printf("\n");

    //Q4, Defining 2 arrays and an array of function pointers, then enumerating the return values of each function for both arrays

    float arr1[] = {1, 3, 9, -1, 2, 11, -3};
    float arr2[] = {2, 3, 5, 7, 9, 1, -5};
    int arr1Size = sizeof(arr1)/sizeof(float);
    int arr2Size = sizeof(arr2)/sizeof(float);

    float (*aggregatesQ4[5])(float arr[], int arrSize) = {minF, maxF, sumF, avgF, pseudo_avg};
    printf("----------------Q4----------------\n");
    printf("Functions used on the first and second array (arr1 and arr2): \n");
    for (int i = 0; i < 5; i++){
        printf(" Function %d on arr1: %f\n", i+1, (*aggregatesQ4[i])(arr1, arr1Size));
        printf(" Function %d on arr2: %f\n", i+1, (*aggregatesQ4[i])(arr2, arr2Size));
    }
    printf("\n");

    //Q5, Creating an alias for aggregates using typedef and printing the corresponding aggregate function names associated with the values
    const char* funcNames[5] = {"MinFunction", "MaxFunction", "SumFunction", "AvgFunction", "PseudoAvgFunction"};
    typedef float (*aggregatesQ5)(float arr[], int arrSize);
    aggregatesQ5 funcs[5] = {minF, maxF, sumF, avgF, pseudo_avg};
    printf("----------------Q5----------------\n");
    printf("Functions used on the first and second array (arr1 and arr2): \n");
    for (int i = 0; i < 5; i++){
        printf(" %s on arr1: %f\n", funcNames[i], (funcs[i])(arr1, arr1Size));
        printf(" %s on arr2: %f\n", funcNames[i], (funcs[i])(arr2, arr2Size));
    }

    return 0;
}