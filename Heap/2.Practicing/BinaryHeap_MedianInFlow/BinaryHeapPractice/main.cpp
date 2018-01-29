//
//  main.cpp
//  BinaryHeapPractice
//
//  Created by Yevgeniy Tolstikov on 28/01/2018.
//  Copyright © 2018 HandMade. All rights reserved.
//

#include <iostream>
#include "min-heap.hpp"
#include "max-heap.hpp"

#define N 4

void add_number(int number, MaxHeap& lowerHeap, MinHeap& upperheap)
{
    if(lowerHeap.size() > 0 && number < lowerHeap.top())
    {
        lowerHeap.push(number);
    }
    else
    {
        upperheap.push(number);
    }
}

void rebalance(MaxHeap& lowerHeap, MinHeap& upperHeap)
{
    if(lowerHeap.size() > upperHeap.size())
    {
        if((lowerHeap.size() - upperHeap.size()) >= 2)
        {
            upperHeap.push(lowerHeap.pop());
        }
    }
    else if(upperHeap.size() > lowerHeap.size())
    {
        if((upperHeap.size() - lowerHeap.size()) >= 2)
        {
            lowerHeap.push(upperHeap.pop());
        }
    }
}

float calculate_meridian(MaxHeap& lowerHeap, MinHeap& upperHeap)
{
    if(lowerHeap.size() > upperHeap.size())
    {
        return lowerHeap.top();
    }
    else if(upperHeap.size() > lowerHeap.size())
    {
        return upperHeap.top();
    }
    else
    {
        return ((float)lowerHeap.top() + upperHeap.top()) / 2.0f;
    }
}

void get_medians(int arr[], int n, float* res)
{
    MaxHeap lowerHeap;
    MinHeap upperHeap;
    
    for(int i = 0; i < n; ++i)
    {
        add_number(arr[i], lowerHeap, upperHeap);
        rebalance(lowerHeap, upperHeap);
        res[i] = calculate_meridian(lowerHeap, upperHeap);
    }
}


int main(int argc, const char * argv[]) {
    
    int n;
    
    std::cin >> n;
    
    int arr[n];
    float res[n];
    
    for(int i = 0; i < n; ++i)
    {
        int k;
        std::cin >> k;
        arr[i] = k;
    }
    
    get_medians(arr, n, res);
    
    for(int i = 0; i < n; ++i)
    {
        std::cout << res[i] << std::endl;
    }
    
    return 0;
}
