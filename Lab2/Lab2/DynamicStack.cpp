#include "DynamicStack.hpp"
#include <iostream>
#include <cstdlib>

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    if (capacity <= 0)
        init_capacity_ = 16;
    else
        init_capacity_ = capacity;
    
    capacity_ = init_capacity_;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
    delete [] items_;
    items_ = NULL;
}

bool DynamicStack::empty() const
{
    return !size_;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if (size_ == capacity_)
    {
        StackItem *temp = new StackItem[capacity_];
        for (int i = 0; i < size_; i++)
            temp[i] = items_[i];
        delete [] items_;
        items_ = new StackItem[capacity_*2];
        for (int i = 0; i < size_; i++)
            items_[i] = temp[i];
        delete [] temp;
        capacity_ *= 2;
    }
    items_[size_] = value;
    size_++;
}

StackItem DynamicStack::pop()
{
    if (empty())
    {
        return EMPTY_STACK;
    }
    else
    {
        size_--;
        StackItem popped = items_[size_];
        if (size_ <= (capacity_/4))
        {
            if (capacity_/2 >= init_capacity_)
            {
                StackItem *temp = new StackItem[capacity_];
                for (int i = 0; i < size_; i++)
                    temp[i] = items_[i];
                delete [] items_;
                items_ = new StackItem[capacity_/2];
                for (int i = 0; i < size_; i++)
                    items_[i] = temp[i];
                delete [] temp;
                capacity_ /= 2;
            }
        }
        return popped;
    }
}

StackItem DynamicStack::peek() const
{
    if (empty())
    {
        return EMPTY_STACK;
    }
    else
    {
        return items_[size_ - 1];
    }
}

void DynamicStack::print() const
{
    for (int i = size_ - 1; i >= 0; i--)
    {
        std::cout << "[" << items_[i] << "]";
    }
    std::cout << std::endl;
}
