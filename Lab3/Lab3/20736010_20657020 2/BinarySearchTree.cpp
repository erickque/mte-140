#include "BinarySearchTree.hpp"
#include <iostream>

// Implement the functions here.

typedef BinarySearchTree::DataType DataType;
typedef BinarySearchTree::Node Node;

BinarySearchTree::Node::Node(DataType newval)
{
    val = newval;
    left = right = nullptr;
}

BinarySearchTree::BinarySearchTree()
{
    root_ = nullptr;
    size_ = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    while (size_ > 0)
        remove(max());
    while (size_ > 0)
        remove(min());
}

bool BinarySearchTree::exists(DataType val) const
{
    Node* temp = root_;
    
    while (temp != nullptr)
    {
        if (temp->val == val) return true;
        if (val < temp->val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

DataType BinarySearchTree::min() const
{
    Node* temp = root_;
    
    while (temp->left != nullptr)
        temp = temp->left;
    
    return temp->val;
}

DataType BinarySearchTree::max() const
{
    Node* temp = root_;
    
    while (temp->right != nullptr)
        temp = temp->right;
    
    return temp->val;
}

unsigned int BinarySearchTree::size() const
{
    return size_;
}

unsigned int BinarySearchTree::depth() const
{
    if (size() == 1)
        return 0;
    else
        return getNodeDepth(root_);
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
    if (n == nullptr)
    {
        return -1;
    }
    else
    {
        int leftDepth = getNodeDepth(n->left);
        int rightDepth = getNodeDepth(n->right);
        
        if (leftDepth > rightDepth)
            return leftDepth + 1;
        else
            return rightDepth + 1;
    }
}

void BinarySearchTree::print() const
{
    std::function<void(Node*, int)> printLevel = [&printLevel](Node* n, int l)
    {
        if (n == nullptr) return;
        if (l == 1)
            std::cout << n->val;
        else
        {
            printLevel(n->left, l - 1);
            std::cout << " ";
            printLevel(n->right, l - 1);
        }
    };
    
    for (int i = 1; i <= depth() + 1; i++)
    {
        printLevel(root_, i);
        std::cout << std::endl;
    }
}

bool BinarySearchTree::insert(DataType val)
{
    if (size() == 0)
    {
        root_ = new Node(val);
        size_++;
        return true;
    }
    
    if (exists(val)) return false;
    
    Node* temp = root_;
    Node* curr = root_;
    
    while (curr != nullptr)
    {
        temp = curr;
        if (val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    
    if (val < temp->val)
        temp->left = new Node(val);
    else
        temp->right = new Node(val);
    
    size_++;
    
    return true;
}

Node* deleteNode(Node* root, int val)
{
    if (root == nullptr) return root;
    
    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
    else
    {
        // If there is no child or only one child
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // If there are two children
        else
        {
            Node* temp = root->right;
            // Finds the smallest val in the right subtree
            while (temp->left != nullptr)
                temp = temp->left;
            
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root; // Returns the updated root node
}

bool BinarySearchTree::remove(DataType val)
{
    if (!exists(val)) return false;
    
    size_--;
    root_ = deleteNode(root_, val);
    return true;
}


