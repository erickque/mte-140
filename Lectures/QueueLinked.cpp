class QueueLinked
{
public:
	typedef int QueueItem;
	// Only going to create EMPTY_QUEUE once for all instances
	static const QueueItem EMPTY_QUEUE;

	// Ctor/dtor
	QueueLinked();
	~QueueLinked();

	// 3 primary queue methods
	void enqueue(QueueItem item);
	QueueItem dequeue();
	QueueItem peek();

private:
	struct QueueNode
	{
		QueueNode* next;
		QueueItem item;
		// Ctor
		QueueNode(QueueItem newitem) { item = newitem; next = nullptr; }
	};

	QueueNode* front;
	QueueNode* rear;
};
typedef QueueLinked::QueueItem QueueItem;
const QueueItem QueueLinked::EMPTY_QUEUE = -1;



QueueLinked::QueueLinked()
{
	front = nullptr;
	rear = nullptr;  // or NULL
}

QueueLinked::~QueueLinked()
{
	while (front != nullptr)
		dequeue();
}

void QueueLinked::enqueue(QueueItem item)
{
	// Only accept values >=0
	if (item < 0)
		return;

	QueueNode* newnode = new QueueNode(item);
	if (front == nullptr)
	{
		// This is a new queue. Insert first node.
		front = newnode;
		rear = newnode;
	}
	else
	{
		// Something's already in the queue. Enqueue into the rear.
		rear->next = newnode;
		rear = newnode;
	}
}

QueueItem QueueLinked::dequeue()
{
	if (front == nullptr)
		return EMPTY_QUEUE;

	// First, store a copy of the front's item
	QueueItem front_item = front->item;
	// Store it so we can delete it after updating pointers
	QueueNode* temp = front;
	// Move to the next QueueNode in line
	front = front->next;

	if (front == nullptr)
		rear = nullptr;

	// Free the old front's memory
	delete temp;
	return front_item;
}

QueueItem QueueLinked::peek()
{
	if (front == nullptr)
		return EMPTY_QUEUE;
	
	// Same as (*front).item
	return front->item;
}