//
//  main.c
//  BinarySearchDemo
//
//  Created by Vicent on 2019/1/9.
//  Copyright © 2019 VicentZ. All rights reserved.
//

#include <stdio.h>

int binarySearch(int *a, int count, int key) {
    int low = 0;
    int high = count - 1;
    while (low <= high) {
        int mid = (low + high)/2;
        int midVal = a[mid];
        if (midVal < key) {
            low = mid + 1;
        } else if (midVal > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[5] = {1,2,3,4,5};
    int num = binarySearch(a, 5, 2);
    printf("元素的索引为:%d\n",num);
    return 0;
}
