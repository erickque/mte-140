#pragma once

#include <string>
#include <queue>
using namespace std;

// A class Queue to adhere to the course syntax
class Queue
{
public:
	bool enqueue(char c)
	{
		q.push(c);
		return true;
	}

	char dequeue()
	{
		char c = q.front();
		q.pop();
		return c;
	}

	char peek()
	{
		return q.front();
	}

	bool empty()
	{
		return q.empty();
	}

private:
	queue<char> q;
};