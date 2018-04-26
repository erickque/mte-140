#include<cstring>
#include<iostream>
#include<cstdlib>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    capacity_ = 16;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
    size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
    capacity_ = capacity;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
    size_ = 0;
}

CircularQueue::~CircularQueue()
{
    delete [] items_;
    items_ = NULL;
}

bool CircularQueue::empty() const
{
    return !size_;
}

bool CircularQueue::full() const
{
    return size_ == capacity_;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if (full())
    {
        return false;
    }
    else
    {
        items_[tail_] = value;
        size_++;
        
        if (tail_ + 1 >= capacity_)
            tail_ = 0;
        else
            tail_++;
        
        return true;
    }
}

QueueItem CircularQueue::dequeue()
{
    if (empty())
    {
        return EMPTY_QUEUE;
    }
    else
    {
        QueueItem dequeued = items_[head_];
        size_--;

        if (head_ + 1 >= capacity_)
            head_ = 0;
        else
            head_++;
        
        return dequeued;
    }
}

QueueItem CircularQueue::peek() const
{
    if (empty())
    {
        return EMPTY_QUEUE;
    }
    else
    {
        return items_[head_];
    }
}

void CircularQueue::print() const
{
    if (!empty())
    {
        if (tail_ > head_)
        {
            for (int i = head_; i < tail_; i++)
                std::cout << "[" << items_[i] << "]";
        }
        else
        {
            for (int i = head_; i < capacity_; i++)
                std::cout << "[" << items_[i] << "]";
            for (int i = 0; i < tail_; i++)
                std::cout << "[" << items_[i] << "]";
        }
        std::cout << std::endl;
    }
    
}
