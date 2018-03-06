#include "SequentialList.hpp"
#include <iostream>

using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	size_ = 0;
	data_ = new DataType[capacity_];
}

SequentialList::~SequentialList()
{
	delete [] data_;
	data_ = nullptr;
}

bool SequentialList::empty() const
{
	return !size_;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	return size_ == capacity_;
}

void SequentialList::print() const
{
	if (!empty())
	{
		for (int i = 0; i < size_; i++)
			cout << "[" << data_[i] << "]";
		cout << endl;
	}
	else
	{
		cout << "Empty!" << endl;
	}
}

bool SequentialList::insert_front(DataType val)
{
    if (full()) return false;
    
    for (int i = size_; i > 0; i--)
        data_[i] = data_[i-1];
    data_[0] = val;
    size_++;
    return true;
}

bool SequentialList::remove_front()
{
    if (empty()) return false;

    for (int i = 0; i < size_-1; i++)
        data_[i] = data_[i+1];
    size_--;
    return true;
}

bool SequentialList::insert_back(DataType val)
{
    if (full()) return false;

    data_[size_] = val;
    size_++;
    return true;
}

bool SequentialList::remove_back()
{
    if (empty()) return false;

    size_--;
    return true;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (full() || index > size_) return false;

    if (size_ == 0)
    {
        data_[0] = val;
    }
    else
    {
        for (int i = size_; i > index; i--)
            data_[i] = data_[i-1];
        data_[index] = val;
    }
    size_++;
    return true;
}

bool SequentialList::remove(unsigned int index)
{
    if (empty() || index >= size_) return false;

    for (int i = index; i < size_ - 1; i++)
        data_[i] = data_[i+1];
    size_--;
    return true;
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i < size_; i++)
		if (data_[i] == val)
			return i;
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index < size_)
		return data_[index];
    
	return data_[size_-1]; // Returns last element for invalid index
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if (index < size_)
	{
		data_[index] = val;
		return true;
	}
	return false;
}
