//
//  FunctionC.c
//  BubblingSortDemo
//
//  Created by Vicent on 2019/1/6.
//  Copyright © 2019 VicentZ. All rights reserved.
//

#include "FunctionC.h"

void swapC(int *a,int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbingSortC(int *array, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                swapC(&array[j], &array[j + 1]);
            }
        }
    }
    printf("结果为:");
    for (int i = 0; i < len; i++) {
        printf("%d,",array[i]);
    }
}

void testSortC() {
    int arrayC[5] = {2,1,7,3,5};
    bubbingSortC(arrayC,5);
    printf("end");
}

int partion(int *array, int low, int high) {
    int pivot = array[low];
    while (low < high) {
        while (low < high && array[high] > pivot) {
            high--;
        }
        array[low] = array[high];
        while (low < high && array[low] <= pivot) {
            low++;
        }
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}

void quickSort(int *array, int low, int high) {
    int loc = 0;
    if (low < high) {
        loc = partion(array, low, high);
        quickSort(array, low, loc - 1);
        quickSort(array, loc + 1, high);
    }
}

void testQuickSortC() {
    int arrayC[5] = {2,1,7,3,5};
    quickSort(arrayC, 0, 4);
    printf("result is:");
    for (int i = 0; i < 5; i++) {
        printf("%d,",arrayC[i]);
    }
}
