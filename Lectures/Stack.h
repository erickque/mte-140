#pragma once

#include <stack>
using namespace std;

// A class Stack to adhere to the course syntax
class Stack
{
public:
	bool push(char c)
	{
		s.push(c);
		return true;
	}

	char pop()
	{
		char c = s.top();
		s.pop();
		return c;
	}

	char peek()
	{
		return s.top();
	}

	bool empty()
	{
		return s.empty();
	}

private:
	stack<char> s;
};