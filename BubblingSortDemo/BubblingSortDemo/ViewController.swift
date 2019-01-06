//
//  ViewController.swift
//  BubblingSortDemo
//
//  Created by Vicent on 2019/1/6.
//  Copyright © 2019 VicentZ. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
//        var array = [2,1,7,3,5]
//        array = bubbingSort(array: &array)
//        print("result is \(array)")
//        testSortC()
        
//        FunctionOC.testSortOC()
//        testQuickSortSwift(array: &array)
        reload((Any).self);
    }
    
    @IBAction func reload(_ sender: Any) {
//        var array = [2,1,7,3,5]
//        testQuickSortSwift(array: &array)
//        testQuickSortC()
        FunctionOC.testQuickSortOC()
    }
    
    func bubbingSort(array:inout Array<Int>) -> Array<Int> {
        for i in 0..<array.count - 1 {
            for j in 1..<array.count - i {
                if (array[j - 1] < array[j]) {
                    array.swapAt(j - 1, j)
                }
            }
        }
        return array;
    }
    
    func partition(array:inout Array<Int>, low: Int, high: Int) -> Int {
        let pivot = array[low];
        var tmpH = high;
        var tmpL = low;
        while tmpL < tmpH {
            while low < high && array[tmpH] > pivot {
                tmpH-=1
            }
            array[tmpL] = array[tmpH]
            while tmpL < tmpH && array[tmpL] <= pivot {
                tmpL+=1
            }
            array[tmpH] = array[tmpL]
        }
        array[tmpL] = pivot
        return tmpL;
    }
    
    func quickSort(array:inout Array<Int>, low: Int, high: Int) {
        var loc = 0
        if low < high {
            loc = partition(array: &array, low: low, high: high);
            quickSort(array: &array, low: low, high: loc - 1)
            quickSort(array: &array, low: loc + 1, high: high)
        }
    }
    
    func testQuickSortSwift(array:inout Array<Int>) {
        quickSort(array: &array, low: 0, high: array.count - 1)
        print("result is:")
        for item in array {
            print("\(item),");
        }
    }

}
