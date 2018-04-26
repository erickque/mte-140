#include "PriorityQueue.hpp"
#include <iostream>

// Implement the functions here.

typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
    heap_ = new DataType[capacity + 1];
    size_ = 0;
    capacity_ = capacity;
}

PriorityQueue::~PriorityQueue()
{
    delete [] heap_;
    heap_ = nullptr;
}

DataType PriorityQueue::max() const
{
    if (empty()) return -1;
    return heap_[1];
}

bool PriorityQueue::empty() const
{
    return !size_;
}

bool PriorityQueue::full() const
{
    return size_ == capacity_;
}

unsigned int PriorityQueue::size() const
{
    return size_;
}

void PriorityQueue::print() const
{
    for (int i = 1; i <= size_; i++)
        std::cout << "[" << heap_[i] << "]";
    std::cout << std::endl;
}

bool PriorityQueue::enqueue(DataType val)
{
    if (full()) return false;
    
    if (empty())
    {
        heap_[1] = val;
    }
    else
    {
        // Insert in bottom-right-most leaf
        unsigned int index = size_ + 1;
        heap_[index] = val;
        
        while ((heap_[index/2] < heap_[index]) && index > 1)
        {
            std::swap(heap_[index/2], heap_[index]);
            index /= 2;
        }
    }
    size_++;
    return true;
}

bool PriorityQueue::dequeue()
{
    if (empty()) return false;
    // Replace root node with bottom-right-most leaf
    unsigned int index = 1;
    heap_[index] = heap_[size_];
    unsigned int leftChild = 2*index;
    unsigned int rightChild = 2*index + 1;
    
    // Recurse downwards, swapping with largest child
    while ((heap_[index] < heap_[leftChild] || heap_[index] < heap_[rightChild])
           && leftChild <= size_)
    {
        if (heap_[rightChild] > heap_[leftChild] && rightChild <= size_)
        {
            std::swap(heap_[rightChild], heap_[index]);
            index = rightChild;
        }
        else
        {
            std::swap(heap_[leftChild], heap_[index]);
            index = leftChild;
        }
        leftChild = 2*index;
        rightChild = 2*index + 1;
    }
    size_--;
    return true;
}




