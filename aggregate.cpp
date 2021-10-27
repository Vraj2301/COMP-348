#include <stdio.h>
#include <cstdlib>
#include "aggregate.h"

//Finds the minimum value of the array of floats
float minF(float *arr, int arrSize) {
    if (arrSize == 0) {
#line 41
        fprintf(stderr, "FATAL ERROR in line %d", __LINE__);
        exit(1);
    }

    float minNum = arr[0];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < minNum)
            minNum = arr[i];
    }
    return minNum;
}

//Finds the maximum value of the array of floats
float maxF(float *arr, int arrSize) {
    if (arrSize == 0) {
#line 41
        fprintf(stderr, "FATAL ERROR in line %d", __LINE__);
        exit(1);
    }

    float maxNum = arr[0];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > maxNum)
            maxNum = arr[i];
    }
    return maxNum;
}

//Computes the sum of the array of floats
float sumF(float *arr, int arrSize) {
    if (arrSize == 0) {
#line 41
        fprintf(stderr, "FATAL ERROR in line %d", __LINE__);
        exit(1);
    }

    float arrSum = 0;

    for (int i = 0; i < arrSize; i++) {
        arrSum += arr[i];
    }
    return arrSum;
}

//Computes the average of the array of floats
float avgF(float arr[], int arrSize) {
    if (arrSize == 0) {
#line 41
        fprintf(stderr, "FATAL ERROR in line %d", __LINE__);
        exit(1);
    }

    float arrAvg = ((sumF(arr, arrSize))/arrSize);
    return arrAvg;
}

//Computes the pseudo-average of the array of floats
float pseudo_avg(float arr[], int arrSize) {
    if (arrSize == 0) {
#line 41
        fprintf(stderr, "FATAL ERROR in line %d", __LINE__);
        exit(1);
    }

    float minNum = minF(arr, arrSize);
    float maxNum = maxF(arr, arrSize);
    float arrAvg = (minNum + maxNum)/2;
    return arrAvg;

}