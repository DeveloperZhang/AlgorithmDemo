//
//  FunctionOC.m
//  BubblingSortDemo
//
//  Created by Vicent on 2019/1/6.
//  Copyright © 2019 VicentZ. All rights reserved.
//

#import "FunctionOC.h"

@implementation FunctionOC

+ (void)bubbingSortOC:(NSMutableArray<NSNumber *> *)array {
    NSUInteger len = array.count;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 1; j < len - i; j++) {
            if (array[j - 1].intValue < array[j].intValue) {
                [array exchangeObjectAtIndex:j-1 withObjectAtIndex:j];
            }
        }
    }
    NSLog(@"结果为:");
    NSMutableString *mString = [@"" mutableCopy];
    [array enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [mString appendFormat:@"%@",obj];
    }];
    NSLog(@"%@", mString);
}


+ (void)bubbingSortUpOC:(NSMutableArray<NSNumber *> *)array {
    NSUInteger len = array.count;
    NSUInteger k = len - 1,pos = 0;
    BOOL flag = false;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < k; j++) {
            if (array[j].intValue < array[j + 1].intValue) {
                [array exchangeObjectAtIndex:j withObjectAtIndex:j + 1];
                flag = 1;
                pos = j;
            }
        }
        k = pos;
        if (flag == false) {
            break;
        }
    }
    NSLog(@"结果为:");
    NSMutableString *mString = [@"" mutableCopy];
    [array enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [mString appendFormat:@"%@",obj];
    }];
    NSLog(@"%@", mString);
}

+ (void)testSortOC {
    NSMutableArray *array = [@[@2,@1,@7,@3,@5] mutableCopy];
//    [self bubbingSortOC:array];
    [self bubbingSortUpOC:array];
}


+ (NSUInteger)partion:(NSMutableArray<NSNumber *> *)array low:(NSUInteger)low high:(NSUInteger)high {
    NSInteger pivot = array[low].integerValue;
    while (low < high) {
        while (low < high && array[high].integerValue > pivot) {
            high--;
        }
        array[low] = array[high];
        while (low < high && array[low].integerValue <= pivot) {
            low++;
        }
        array[high] = array[low];
    }
    array[low] = [NSNumber numberWithInteger:pivot];
    return low;
}

+ (void)quickSortOC:(NSMutableArray<NSNumber *> *)array low:(NSInteger)low high:(NSInteger)high{
    NSInteger loc = 0;
    if (low < high) {
        loc = [self partion:array low:low high:high];
        [self quickSortOC:array low:low high:loc - 1];
        [self quickSortOC:array low:loc + 1 high:high];
    }
}

+ (void)testQuickSortOC {
    NSMutableArray *array = [@[@2,@1,@7,@3,@5] mutableCopy];
    [self quickSortOC:array low:0 high:array.count - 1];
    NSLog(@"结果为:");
    NSMutableString *mString = [@"" mutableCopy];
    [array enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [mString appendFormat:@"%@",obj];
    }];
    NSLog(@"%@", mString);
}

@end
