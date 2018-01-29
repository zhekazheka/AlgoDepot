//
//  MinHeap.hpp
//  BinaryHeapPractice
//
//  Created by Yevgeniy Tolstikov on 28/01/2018.
//  Copyright © 2018 HandMade. All rights reserved.
//

#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <iostream>

struct MinHeap
{
private:
    // vector to store heap elements
    std::vector<int> A;
    
    // return parent of A[i]
    // don't call this function if it is already a root node
    int PARENT(int i)
    {
        return (i - 1) / 2;
    }
    
    // return left child of A[i]
    int LEFT(int i)
    {
        return (2 * i + 1);
    }
    
    // return right child of A[i]
    int RIGHT(int i)
    {
        return (2 * i + 2);
    }
    
    // Recursive Heapify-down algorithm
    // the node at index i and its two direct children
    // violates the heap property
    void heapify_down(int i)
    {
        // get left and right child of node at index i
        int left = LEFT(i);
        int right = RIGHT(i);
        
        int smallest = i;
        
        // compare A[i] with its left and right child
        // and find smallest value
        if (left < size() && A[left] < A[i])
            smallest = left;
        
        if (right < size() && A[right] < A[smallest])
            smallest = right;
        
        // swap with child having lesser value and
        // call heapify-down on the child
        if (smallest != i) {
            std::swap(A[i], A[smallest]);
            heapify_down(smallest);
        }
    }
    
    // Recursive Heapify-up algorithm
    void heapify_up(int i)
    {
        // check if node at index i and its parent violates
        // the heap property
        if (i && A[PARENT(i)] > A[i])
        {
            // swap the two if heap property is violated
            std::swap(A[i], A[PARENT(i)]);
            
            // call Heapify-up on the parent
            heapify_up(PARENT(i));
        }
    }
    
public:
    // return size of the heap
    unsigned int size()
    {
        return A.size();
    }
    
    // function to check if heap is empty or not
    bool empty()
    {
        return size() == 0;
    }
    
    // insert key into the heap
    void push(int key)
    {
        // insert the new element to the end of the vector
        A.push_back(key);
        
        // get element index and call heapify-up procedure
        int index = size() - 1;
        heapify_up(index);
    }
    
    // function to remove element with highest priority (present at root)
    int pop()
    {
        try {
            // if heap has no elements, throw an exception
            if (size() == 0)
                throw std::out_of_range("Vector<X>::at() : "
                                   "index is out of range(Heap underflow)");
            
            // replace the root of the heap with the last element
            // of the vector
            int root = A[0];
            A[0] = A.back();
            A.pop_back();
            
            // call heapify-down on root node
            heapify_down(0);
            
            return root;
        }
        // catch and print the exception
        catch (const std::out_of_range& oor) {
            std::cout << "\n" << oor.what();
        }
        
        return -1;
    }
    
    // function to return element with highest priority (present at root)
    int top()
    {
        try {
            // if heap has no elements, throw an exception
            if (size() == 0)
                throw std::out_of_range("Vector<X>::at() : "
                                   "index is out of range(Heap underflow)");
            
            // else return the top (first) element
            return A.at(0);	// or return A[0];
        }
        // catch and print the exception
        catch (const std::out_of_range& oor) {
            std::cout << "\n" << oor.what();
        }
        
        return -1;
    }
};

#endif /* MinHeap_hpp */
