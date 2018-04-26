// Linked implementation of the stack ADT
class StackLinked
{
public:
	// Types of items that are being put into the stack
	typedef int StackItem;
	// Returned when peeking/popping an empty stack
	static const StackItem EMPTY_STACK;

	// Constructor/destructor
	StackLinked();
	~StackLinked();

	// 3 primary stack methods
	void push(StackItem item);
	StackItem pop();
	StackItem peek();

private:
	struct StackNode
	{
		StackNode* next;  // going "down" the stack
		StackItem item;  // integer that this stack node stores
		StackNode(StackItem newitem) { item = newitem; next = nullptr; }
	};

	// Pointer to the top of the stack
	StackNode* top;
};
typedef StackLinked::StackItem StackItem;



StackLinked::StackLinked()
{
	top = nullptr;
}

StackLinked::~StackLinked()
{
	while (top != nullptr) {
		pop();
	}
}

void StackLinked::push(StackItem item)
{
	StackNode* newnode = new StackNode(item);
	newnode->next = top;
	top = newnode;
}

StackItem StackLinked::pop()
{
	//if (top == nullptr)
		//return StackLinked::EMPTY_STACK;

	// Look at the top item before we remove top node
	// Both of these are effectively the same.
	//StackItem top_item = peek();
	StackItem top_item = top->item;
	
	// Store temporary pointer to current top (to be deleted)
	StackNode* old_top = top;
	// Update top
	top = top->next;
	delete old_top;

	return top_item;
}

StackItem StackLinked::peek()
{
	//if (top == nullptr)
		//return StackLinked::EMPTY_STACK;

	// Same as: (*top).item
	return top->item;
}