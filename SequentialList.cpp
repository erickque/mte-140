class SequentialList
{
public:
	SequentialList();
	~SequentialList();
	void insert(int value, int position);
	void remove(int position);
	int select(int position);
	void replace(int postion, int value);
	int size();
private:
	int data;
	unsigned int capacity;
	unsigned int size;
}

SequentialList::SequentialList()
{
	data = new int[8];
}

void SequentialList::insert(int value, int position)
{
	// Shift right
	size++;
}

void SequentialList::remove(int position)
{
	// Shift right
	size++;
}

void SequentialList::replace(int value, int position)
{
	data[position] = value;
}

int SequentialList::size()
{
	return size;
}