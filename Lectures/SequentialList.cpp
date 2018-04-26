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

SequentialList::

