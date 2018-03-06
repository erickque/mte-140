#include "DoublyLinkedList.hpp"
#include <iostream>

using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	prev = next = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = tail_ = nullptr;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if (!empty())
	{
		Node* curr = head_;
		while (curr != nullptr)
		{
			Node* next = curr->next;
			delete curr;
			curr = next;
		}
	}
    else
    {
        head_ = tail_ = nullptr;
    }
}

bool DoublyLinkedList::empty() const
{
	return !size_;
}

bool DoublyLinkedList::full() const
{
	return size_ == CAPACITY;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

void DoublyLinkedList::print() const
{
	if (!head_) return;
	Node* curr = head_;
	while (curr != nullptr)
	{
		cout << "[" << curr->value << "]";
		curr = curr->next;
		if (curr != nullptr)
		{
			cout << "->";
		}
	}
	cout << endl;
}

bool DoublyLinkedList::insert_front(DataType value)
{
    if (full()) return false;
		
    if (empty())
    {
        head_ = tail_ = new Node(value);
        head_->prev = nullptr;
        tail_->next = nullptr;
    }
    else
    {
        Node* temp = new Node(value);
        head_->prev = temp;
        temp->next = head_;
        temp->prev = nullptr;
        head_ = temp;
    }
    size_++;
    return true;
}

bool DoublyLinkedList::remove_front()
{
    if (empty()) return false;

    if (size_ == 1)
    {
        delete head_;
        head_ = tail_ = nullptr;
    }
    else
    {
		head_ = head_->next;
		delete head_->prev;
		head_->prev = nullptr;
	}
    size_--;
	return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
    if (full()) return false;
    if (empty())
    {
        tail_ = head_ = new Node(value);
        tail_->next = nullptr;
        head_->prev = nullptr;;
    }
    else
    {
        Node* temp = new Node(value);
        tail_->next = temp;
        temp->prev = tail_;
        tail_ = temp;
        tail_->next = nullptr;
    }
    size_++;
    return true;
}

bool DoublyLinkedList::remove_back()
{
    if (empty()) return false;
		
    if (size_ == 1)
    {
        delete tail_;
        tail_ = head_ = nullptr;
    }
    else
    {
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = nullptr;
    }
    size_--;
	return true;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (full() || index > size_) return false;

    if (index == 0)
        return insert_front(value);
    if (index == size_)
        return insert_back(value);

    Node* newNode = new Node(value);
    Node* oldNode = getNode(index);

    oldNode->prev->next = newNode;
    newNode->prev = oldNode->prev;
    oldNode->prev = newNode;
    newNode->next = oldNode;
    
    size_++;
    return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if (empty() || index >= size_) return false;
    
    if (index == 0)
        return remove_front();
    if (index == size_-1)
        return remove_back();
    
    Node* remove = getNode(index);

    remove->prev->next = remove->next;
    remove->next->prev = remove->prev;
    delete remove;
    
    size_--;
    return true;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    if (empty()) return 0;
    
	Node* curr = head_;
    for (unsigned int i = 0; i < size_; i++)
	{
		if (curr->value == value)
			return i;
		curr = curr->next;
	}
	return size_;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if (empty()) return 0;
    
    if (index >= size_)
        return tail_->value;
    
    Node* select = getNode(index);
    return select->value;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if (empty() || index >= size_) return false;

    Node* replace = getNode(index);
    replace->value = value;
    return true;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    Node* curr = head_;
    for (unsigned int i = 0; i < index; i++)
        curr = curr->next;
    return curr;
}
